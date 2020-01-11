from pyknon.MidiFile import MIDIFile
#import random, collections

def midi_dur(dur):
  return dur * 4

def midi_track(midi, num, name, tempo):
	midi.addTrackName(num, 0, name)
	midi.addTempo(num, 0, tempo)
	return num

midi_data = MIDIFile(2)
channel = 0
tempo = 120

track1 = midi_track(midi_data, 0, "pan", tempo)
track2 = midi_track(midi_data, 1, "mod", tempo)

time = 0
for paramerter1 in range(0, 127, 10):
	midi_data.addControllerEvent(track1, channel, time, 10, paramerter1)
	midi_data.addControllerEvent(track2, channel, time, 1, paramerter1)
	time += midi_dur(1 / 16)

with open("cc-example.mid", "wb") as fout:
	midi_data.writeFile(fout)
