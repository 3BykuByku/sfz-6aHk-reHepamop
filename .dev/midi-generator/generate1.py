from itertools import chain
from pyknon.genmidi import Midi
from pyknon.music import Note, NoteSeq
import random, collections
import bpsets

"""
# rotate
d = collections.deque([1,2,3,4,5])
print(d)
for i in range(4):
	d.rotate(-1)
	print(d)
exit()
"""

def durations1():
	return 1 / random.choice([2, 4, 8, 16])
	#return 1 / random.choice([32, 8, 64, 16])
	#return 1 / random.randint(1, 16)

def notes1():
	#return random.choice(range(12)), random.choice([2])
	return random.choice(bpsets.data[7][7]), random.choice([2])

# drums
def notes2():
	result = random.choice([35, 38, 41, 43, 51])
	return result % 12, result // 12

def chords3():
	size = 6
	#return zip(
	#	random.choice(bpsets.data[size]),
	#	[random.choice([2, 4]) for i in range(size)]
	#)
	result = []
	notes = random.choice(bpsets.data[size])
	for i in range(size):
		result.append((notes[i], random.choice([2, 4])))
	return result

nsize = 3 # get random notes for each track
group_notes1 = [notes1() for i in range(nsize)]
group_drums1 = [notes2() for i in range(nsize)]
group_keys1 = [chords3() for i in range(nsize)]

print(group_notes1)
print(group_drums1)
print(group_keys1)

# repeat notes group with different durations
#notes_durations = []
#for i in range(4):
#	notes_durations += [durations1() for i in group_notes1]

track_notes1 = []
track_drums1 = []
track_keys1 = []
for i in range(6): # repeat N times
	for j, note in enumerate(group_notes1):
		d = durations1()

		n, o = group_notes1[j]
		track_notes1.append(Note(value=n, octave=o, dur=d))

		n, o = group_drums1[j]
		track_drums1.append(Note(value=n, octave=o, dur=d))

		# chords example
		chord = []
		for n, o in group_keys1[j]:
			chord.append(Note(value=n, octave=o, dur=d))
		track_keys1.append(NoteSeq(chord))

#exit()

# https://en.wikipedia.org/wiki/General_MIDI#Program_change_events
midi1 = Midi(
	tempo=70,
	number_tracks=3,
	channel=[0, 9, 1],
	instrument=[34, 0, 27]
)
midi1.seq_notes(NoteSeq(track_notes1), track=0, channel=0)
midi1.seq_notes(NoteSeq(track_drums1), track=1, channel=9)
midi1.seq_chords(track_keys1, track=2, channel=1)
midi1.write("result1.mid")

"""
notes1 = NoteSeq("D4 F#8 A Bb4")
notes2 = NoteSeq([Note(2, dur=1/4), Note(6, dur=1/8),
Note(9, dur=1/8), Note(10, dur=1/4)])
midi = Midi(number_tracks=2, tempo=90)
midi.seq_notes(notes1, track=0)
midi.seq_notes(notes2, track=1)
midi.write("test1.mid")
"""

"""
def pascals_triangle(n):
    x = [1]
    yield x
    for i in range(n - 1):
        x = [sum(i) for i in zip([0] + x, x + [0])]
        yield x

seq = chain.from_iterable(pascals_triangle(30))
midi = Midi(tempo=120)
midi.seq_notes(NoteSeq([Note(x % 12, 4, 1 / 16) for x in seq]))
midi.write("pascal.mid")

"""

"""
# Notes on two tracks using the defaults

notes1 = NoteSeq("C4.'' B8' A4 D")
notes2 = NoteSeq("E4 F G4. A8")

m = Midi(2, tempo=100, instrument=[12, 14])
m.seq_notes(notes1, track=0)
m.seq_notes(notes2, track=1)
m.write("tracks.mid")

# Chords on two tracks using the defaults

chords1 = [NoteSeq("C2 E G"), NoteSeq("G2 B D")]
chords2 = [NoteSeq("C,4 E"), NoteSeq("E, G"), NoteSeq("G, B"), NoteSeq("B, D'")]

midi = Midi(2, tempo=60, instrument=[40, 20])
midi.seq_chords(chords1, track=0)
midi.seq_chords(chords2, track=1)
midi.write("chords.mid")

# Notes on two tracks using percussion

# In the MIDI library, the tracks and channels are numbered from 0,
# While the MIDI Standard is numbered from 1,
# So to use percussion you must use channel 9 in the library

n1 = NoteSeq("C4 D E F")
n2 = NoteSeq("C8 C G, G C' C G, G")


"""