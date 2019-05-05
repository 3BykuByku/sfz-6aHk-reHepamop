import sys, os, csv, re
from os import scandir, walk, getcwd
from os.path import dirname
from collections import namedtuple, defaultdict, OrderedDict

import GM

if (len(sys.argv) > 1):
	samples_path = sys.argv[1]
else:
	samples_path = getcwd()

pattern_order = re.compile("(\d+)\.")

# init samples by folder names and order in file names
samples = {}
for root, dirs, files in os.walk(samples_path):
	for name in files:
		if (".sfz" in name):
			continue
		fname = os.path.join(root, name).replace(samples_path, "")[1:]
		patch_name = dirname(fname)
		if not patch_name in GM.drums:
			print("Error - patch name: " + patch_name)
			continue
		tmp = pattern_order.search(fname)
		if tmp.group(1):
			order = tmp.group(1)
			if not patch_name in samples:
				samples[patch_name] = OrderedDict()
			if not order in samples[patch_name]:
				samples[patch_name][order] = []
			samples[patch_name][order].append(fname)
		else:
			print("Error empty group")

group_template = """
<group> key={code} ampeg_release=.75 ampeg_hold=1 volume=1 pan=0 loop_mode=one_shot {group} {off_by}
"""
patch_template = """<region> lovel={level_min} hivel={level_max} sample={sample_path}"""

with open(samples_path + "/generated.sfz", "w") as fout:
	for patch_name in samples:
		#print(patch_name)
		fout.write("\n// " + GM.drums[patch_name].title + "\n")

		incr = 128 // len(samples[patch_name])
		level_min = 0
		i = 1
		for order in samples[patch_name]:
			#print(samples[patch_name][order])
			j = 1
			size = len(samples[patch_name][order])
			for sample in samples[patch_name][order]:
				#print([level_min, level_min + incr, sample, j])
				data = {
					"code": GM.drums[patch_name].code,
					"level_min": level_min,
					"level_max": 127 if i == len(samples[patch_name]) else level_min + incr - 1,
					"sample_path": sample,
					"group": "group=1" if patch_name == "clhat" else "",
					"off_by": "group=2 off_by=1 off_mode=normal" if patch_name == "ophat" or patch_name == "pehat" else ""
				}
				region = group_template.format(**data) if j == 1 else ""
				region += patch_template.format(**data)
				if size > 1:
					region += " seq_length={0} seq_position={1}".format(size, j)

				fout.write(region + "\n")

				j += 1
			level_min += incr
			i += 1
