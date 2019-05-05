package main

import (
	"os"
	"fmt"
	"strconv"
	"path/filepath"
	"strings"
	"text/template"
	"encoding/csv"
	"bufio"
	"io"
	"math"
)

func check(e error) {
  if e != nil {
		panic(e)
  }
}

func main() {
	loopMarksPath := os.Args[1]
	hz := 44100
	if len(os.Args) > 2 && os.Args[2] != "-" {
		var err error
		hz, err = strconv.Atoi(os.Args[2])
		check(err)
	}

	regionsType := 0
	if len(os.Args) > 3 {
		var err error
		regionsType, err = strconv.Atoi(os.Args[3])
		check(err)
	}

	fmt.Println(regionsType);
	fmt.Println(hz)
	fmt.Println(loopMarksPath)

	dirname, fname := filepath.Split(loopMarksPath)
	fname = strings.TrimSuffix(fname, filepath.Ext(fname))
	sampleName := fname + ".wav"

	//fmt.Println(dirname)
	//fmt.Println(fname)
	//fmt.Println(sampleName)

	groupTemplate := template.Must(template.New("group").Parse(`
<group> lovel={{.LevelMin}} hivel={{.LevelMax}} sample={{.SamplePath}} loop_mode=loop_continuous
`))
	patchTemplate := template.Must(template.New("region").Parse(
`<region> key={{.Code}} offset={{.Offset}} end={{.End}} loop_start={{.Offset}} loop_end={{.End}}
`))

	fout, err := os.Create(dirname + "/" + fname + ".sfz")
	check(err)
	defer fout.Close()

	fmarks, err := os.Open(loopMarksPath)
	check(err)
	defer fmarks.Close()

	i := 1
	code := 35
	leftp := -1
	rightp := 0
	first := true
	r := csv.NewReader(bufio.NewReader(fmarks))
	r.Comma = '\t'
	//r.Comment = '#'
	for {
		row, err := r.Read()
		if err == io.EOF {
			break
		}
		check(err)

		if regionsType == 0 {
			p, _ := strconv.ParseFloat(strings.Replace(row[0], ",", ".", -1), 64)
			p = math.Floor(p * float64(hz))

			if leftp == -1 {
				leftp = int(p)
				continue
			}
			rightp = int(p)
		} else {
			fmt.Println(i)
			fmt.Println(row)

			p, _ := strconv.ParseFloat(strings.Replace(row[0], ",", ".", -1), 64)
			p = math.Floor(p * float64(hz))
			leftp = int(p)

			p2, _ := strconv.ParseFloat(strings.Replace(row[1], ",", ".", -1), 64)
			p2 = math.Floor(p2 * float64(hz))
			rightp = int(p2)
		}

		data := struct {
      Code int
      LevelMin int
      LevelMax int
      SamplePath string
      Offset int
      End int
    } { code, 0, 127, sampleName, leftp, rightp }
		if first {
			groupTemplate.Execute(fout, data)
		}
		patchTemplate.Execute(fout, data)

		fmt.Println(leftp, rightp)

		first = false
		code += 1
		leftp = rightp
		i++
	}
}
