import csv

# drum patches info
#  https://en.wikipedia.org/wiki/General_MIDI#Percussion
#  http://computermusicresource.com/GM.Percussion.KeyMap.html

drums = {}
with open('GM.csv') as csvfile:
	for row in csv.reader(csvfile, delimiter="\t"):
		if len(row) != 4:
			continue
		drums[row[0]] = (row[1], row[2], row[3], row[0])  # ('code', 'note', 'title', 'pattern')
	with open("GM.py", "w") as fout:
		fout.write("drums = ")
		fout.write(repr(drums))
