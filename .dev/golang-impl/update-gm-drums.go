package main

//drum patches info
//		https://en.wikipedia.org/wiki/General_MIDI#Percussion
//		http://computermusicresource.com/GM.Percussion.KeyMap.html

import (
	"os"
	"fmt"
	"encoding/csv"
	"bufio"
	"io"
)

func check(e error) {
  if e != nil {
		panic(e)
  }
}

func main() {

	fout, err := os.Create("gm/drums.go")
	check(err)
	defer fout.Close()

	fmap, err := os.Open("GM.csv")
	check(err)
	defer fmap.Close()

fmt.Fprintf(fout, `
package gm

type Drum struct {
  Code int
  Note string
  Title string
  Pattern string
}

type DrumsMap map[string]Drum

var Drums = DrumsMap{
`)

	r := csv.NewReader(bufio.NewReader(fmap))
	r.Comma = '\t'
	//r.Comment = '#'
	for {
		row, err := r.Read()
		if err == io.EOF {
			break
		}
		check(err)
		if len(row) != 4 {
			continue
		}

		fmt.Fprintf(fout, `
	"%s": Drum{Code: %s, Note: "%s", Title: "%s", Pattern: "%s"},`,
			row[0], row[1], row[2], row[3], row[0])
	}

	fmt.Fprintf(fout, `
}
`)

}