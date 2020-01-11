import csv
from collections import namedtuple

# drum patches info
#  https://en.wikipedia.org/wiki/General_MIDI#Percussion
#  http://computermusicresource.com/GM.Percussion.KeyMap.html

drum = namedtuple('drum', ['code', 'note', 'title', 'pattern'])

drums = {}
with open('GM.csv') as csvfile:
	for row in csv.reader(csvfile, delimiter="\t"):
		if len(row) != 4:
			continue
		drums[row[0]] = drum(row[1], row[2], row[3], row[0])
	with open("GM.py", "w") as fout:
		fout.write("from collections import namedtuple\n")
		fout.write('drum = namedtuple("drum", ["code", "note", "title", "pattern"])' + "\n\n")
		fout.write("drums = ")
		fout.write(str(drums))
