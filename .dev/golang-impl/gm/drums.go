
package gm

type Drum struct {
  Code int
  Note string
  Title string
  Pattern string
}

type DrumsMap map[string]Drum

var Drums = DrumsMap{

	"kick": Drum{Code: 35, Note: "B0", Title: "Acoustic Bass Drum / Bass Drum 2", Pattern: "kick"},
	"kick2": Drum{Code: 36, Note: "C1", Title: "Bass Drum 1", Pattern: "kick2"},
	"snare": Drum{Code: 38, Note: "D1", Title: "Acoustic Snare / Snare Drum 1", Pattern: "snare"},
	"snar2": Drum{Code: 40, Note: "E1", Title: "Electric Snare / Snare Drum 2", Pattern: "snar2"},
	"rims": Drum{Code: 37, Note: "C#1", Title: "Side Stick / Rimshot", Pattern: "rims"},
	"clap": Drum{Code: 39, Note: "Eb1", Title: "Hand Clap", Pattern: "clap"},
	"lftom": Drum{Code: 41, Note: "F1", Title: "Low Floor Tom / Low Tom 2", Pattern: "lftom"},
	"hftom": Drum{Code: 43, Note: "G1", Title: "High Floor Tom / Low Tom 1", Pattern: "hftom"},
	"ltom": Drum{Code: 45, Note: "A1", Title: "Low Tom / Mid Tom 2", Pattern: "ltom"},
	"lmtom": Drum{Code: 47, Note: "B1", Title: "Low-Mid Tom / Mid Tom 1", Pattern: "lmtom"},
	"hmtom": Drum{Code: 48, Note: "C2", Title: "Hi Mid Tom / High Tom 2", Pattern: "hmtom"},
	"htom": Drum{Code: 50, Note: "D2", Title: "High Tom 1", Pattern: "htom"},
	"ophat": Drum{Code: 46, Note: "Bb1", Title: "Open Hi-hat", Pattern: "ophat"},
	"clhat": Drum{Code: 42, Note: "F#1", Title: "Closed Hi-hat", Pattern: "clhat"},
	"pehat": Drum{Code: 44, Note: "Ab1", Title: "Pedal Hi-hat", Pattern: "pehat"},
	"ride1": Drum{Code: 51, Note: "Eb2", Title: "Ride Cymbal 1", Pattern: "ride1"},
	"ride2": Drum{Code: 59, Note: "B2", Title: "Ride Cymbal 2", Pattern: "ride2"},
	"rbell": Drum{Code: 53, Note: "F2", Title: "Ride Bell", Pattern: "rbell"},
	"spcy": Drum{Code: 55, Note: "G2", Title: "Splash Cymbal", Pattern: "spcy"},
	"chicy": Drum{Code: 52, Note: "E2", Title: "Chinese Cymbal", Pattern: "chicy"},
	"crcy1": Drum{Code: 49, Note: "C#2", Title: "Crash Cymbal 1", Pattern: "crcy1"},
	"crcy2": Drum{Code: 57, Note: "A2", Title: "Crash Cymbal 2", Pattern: "crcy2"},
	"tambo": Drum{Code: 54, Note: "F#2", Title: "Tambourine", Pattern: "tambo"},
	"cowb": Drum{Code: 56, Note: "Ab2", Title: "Cowbell", Pattern: "cowb"},
	"vslap": Drum{Code: 58, Note: "Bb2", Title: "Vibra Slap", Pattern: "vslap"},
	"hbong": Drum{Code: 60, Note: "C3", Title: "High Bongo", Pattern: "hbong"},
	"lbong": Drum{Code: 61, Note: "C#3", Title: "Low Bongo", Pattern: "lbong"},
	"hcong": Drum{Code: 62, Note: "D3", Title: "Mute High Conga", Pattern: "hcong"},
	"ocong": Drum{Code: 63, Note: "Eb3", Title: "Open High Conga", Pattern: "ocong"},
	"lcong": Drum{Code: 64, Note: "E3", Title: "Low Conga", Pattern: "lcong"},
	"htimb": Drum{Code: 65, Note: "F3", Title: "High Timbale", Pattern: "htimb"},
	"ltimb": Drum{Code: 66, Note: "F#3", Title: "Low Timbale", Pattern: "ltimb"},
	"hago": Drum{Code: 67, Note: "G3", Title: "High Agogo", Pattern: "hago"},
	"lago": Drum{Code: 68, Note: "Ab3", Title: "Low Agogo", Pattern: "lago"},
	"cabas": Drum{Code: 69, Note: "A3", Title: "Cabasa", Pattern: "cabas"},
	"marac": Drum{Code: 70, Note: "Bb3", Title: "Maracas", Pattern: "marac"},
	"swhis": Drum{Code: 71, Note: "B3", Title: "Short Whistle", Pattern: "swhis"},
	"lwhis": Drum{Code: 72, Note: "C4", Title: "Long Whistle", Pattern: "lwhis"},
	"sguir": Drum{Code: 73, Note: "C#4", Title: "Short Guiro", Pattern: "sguir"},
	"lguir": Drum{Code: 74, Note: "D4", Title: "Long Guiro", Pattern: "lguir"},
	"clav": Drum{Code: 75, Note: "Eb4", Title: "Claves", Pattern: "clav"},
	"hwood": Drum{Code: 76, Note: "E4", Title: "High Wood Block", Pattern: "hwood"},
	"lwood": Drum{Code: 77, Note: "F4", Title: "Low Wood Block", Pattern: "lwood"},
	"mcuic": Drum{Code: 78, Note: "F#4", Title: "Mute Cuica", Pattern: "mcuic"},
	"ocuic": Drum{Code: 79, Note: "G4", Title: "Open Cuica", Pattern: "ocuic"},
	"mtria": Drum{Code: 80, Note: "Ab4", Title: "Mute Triangle", Pattern: "mtria"},
	"otria": Drum{Code: 81, Note: "A4", Title: "Open Triangle", Pattern: "otria"},
}
