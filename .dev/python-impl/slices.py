import sys, csv
from os.path import basename, splitext, dirname

loop_marks_path = sys.argv[1]
hz = int(sys.argv[2]) if len(sys.argv) > 2 else 44100

fname = splitext(basename(loop_marks_path))[0]
sample_name = fname + ".wav"
code = 35

group_template = """<group> lovel={level_min} hivel={level_max} sample={sample_path} loop_mode=loop_continuous
"""
patch_template = """<region> key={code} offset={offset} end={end}	loop_start={offset} loop_end={end}"""

with open(dirname(loop_marks_path) + "/" + fname + ".sfz", "w") as fout:
	with open(loop_marks_path, newline="") as fmarks:
		leftp = None
		first = True
		for row in csv.reader(fmarks, delimiter="\t"):
			p = round(float(row[0].replace(",", ".")) * hz)
			if leftp == None:
				leftp = p
				continue
			rightp = p
			#print((leftp, rightp))
			data = {
				"code": code,
				"level_min": 0,
				"level_max": 127,
				"sample_path": sample_name,
				"offset": leftp,
				"end": rightp
			}
			region = (group_template.format(**data) if first else "") + patch_template.format(**data)
			first = False
			fout.write(region + "\n")
			code += 1
			leftp = rightp
