
with open("catalog.txt") as f:
	rows = {}
	cardinality = 0
	for line in f:
		if "Cardinality" in line:
			data = []
			cardinality += 1
		elif line.strip() == "":
			rows[cardinality] = data
		else:
			for tmpset in line.strip().split(" "):
				data.append([int(ch, 16) for ch in tmpset])
	with open("_pcsets.py", "w") as fout:
		fout.write("# Pitch Class Set Catalog: 224 prime sets total\n\n")
		fout.write("data = ")
		fout.write(str(rows))
