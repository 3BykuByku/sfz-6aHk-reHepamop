package main

import (
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	//"strings"
	"sort"
	"strconv"
	"text/template"
	"./gm"
)

func check(e error) {
  if e != nil {
		panic(e)
  }
}

var patternOrder = regexp.MustCompile(`(\d+)\.`)
var samples = make(map[string]map[int][]string)
var groupTemplate = template.Must(template.New("group").Parse(`
<group> key={{.Code}} ampeg_release=.75 ampeg_hold=1 volume=1 pan=0 loop_mode=one_shot {{.Group}} {{.OffBy}}
`))
var patchTemplate = template.Must(template.New("region").Parse(
`<region> lovel={{.LevelMin}} hivel={{.LevelMax}} sample={{.SamplePath}} `))

func processFile(path string, f os.FileInfo, err error) error {
	fname := f.Name()
  if filepath.Ext(fname) == ".sfz" || f.IsDir() {
  	return nil
  }
  patchName := filepath.Base(filepath.Dir(path))
  _, ok := gm.Drums[patchName]
  if !ok {
		fmt.Println("Error - patch name: " + patchName)
		return nil
	}
	tmp := patternOrder.FindStringSubmatch(fname)
	if (len(tmp) == 0) {
		fmt.Println("Error - empty group: " + path)
		return nil
	}

  order, _ := strconv.Atoi(tmp[1])
	_, ok = samples[patchName]
	if !ok {
		samples[patchName] = make(map[int][]string)
	}
	_, ok = samples[patchName][order]
	if !ok {
		samples[patchName][order] = []string{}
	}
	samples[patchName][order] = append(samples[patchName][order], patchName + string(os.PathSeparator) + fname)

  return nil
}

func main() {
	samplePath, _ := os.Getwd()
	if len(os.Args) > 1 {
		samplePath = os.Args[1]
	}

	// init samples by folder names and order in file names
	fout, err := os.Create(samplePath + "/generated.sfz")
	check(err)
	defer fout.Close()

	filepath.Walk(samplePath, processFile)

	for patchName, patchSamples := range samples {
		fmt.Fprintf(fout, "\n// " + gm.Drums[patchName].Title + "\n")

		incr := 128 / len(patchSamples)
		levelMin := 0
		i := 1

		// ordering
		sorted := make([]int, len(patchSamples))
		tmp := 0
		for k := range patchSamples {
			sorted[tmp] = k
			tmp++
		}
		sort.Ints(sorted)

		for _, order := range sorted {
			//fmt.Println(patchName, order)
			vsamples := patchSamples[order]
			j := 1
			size := len(vsamples)
			for _, v := range vsamples {
				//fmt.Println(v)
				l := levelMin + incr - 1
				if i == len(patchSamples) {
					l = 127
				}
				g := ""
				if patchName == "clhat" {
					g = "group=1"
				}
				ob := ""
				if patchName == "ophat" || patchName == "pehat" {
					ob = "group=2 off_by=1 off_mode=normal"
				}
				data := struct {
		      Code int
		      LevelMin int
		      LevelMax int
		      SamplePath string
		      Group string
		      OffBy string
		    } { gm.Drums[patchName].Code, levelMin, l, v, g, ob }

		    if j == 1 {
		    	groupTemplate.Execute(fout, data)
		    }
		    patchTemplate.Execute(fout, data)

 				if size > 1 {
 					fmt.Fprintf(fout, "seq_position=%d seq_length=%d", j, size)
 				}
 				fmt.Fprintf(fout, "\n")

 				j += 1
			}
			levelMin += incr
			i += 1
		}
		//fmt.Println("---")
	}
}
