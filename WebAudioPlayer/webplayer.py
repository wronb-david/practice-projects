import sys
import os
import json
import eyed3

def parseID3(filepath):
	audioFile = eyed3.load(filepath)
	if audioFile.tag is not None:
		title = audioFile.tag.title
		artist = audioFile.tag.artist
		album = audioFile.tag.album
		if title is None:
			title = ""
		if artist is None:
			artist = ""
		if album is None:
			album = ""
	else:
		title = ""
		artist = ""
		album = ""
	return {"path" : filepath, "title": title, "artist": artist, "album": album}

def getFileList(target):
	files = [os.path.join(target, f) for f in os.listdir(target) if os.path.isfile(os.path.join(target, f))]
	audioFiles = [a for a in files if str(a).endswith(".mp3")]
	directories = [os.path.join(target, d) for d in os.listdir(target) if os.path.isdir(os.path.join(target, d))]
	for aDirectory in directories:
		audioFiles.extend(getFileList(aDirectory))
	return audioFiles

def getSongData(files):
	songData = []
	for songpath in files:
		songData.append(parseID3(songpath))
	return {"songs" : songData}

def generateJson(target):
	songData = getSongData(getFileList(target))
	jsonText = json.dumps(songData)
	return jsonText

def checkDirectory(target):
	if os.path.isdir(target):
		jsonText = generateJson(target)
		with open('library.js', 'w') as json_file:
			json_file.write("webplayer.library.data = ")
			json_file.write(jsonText)

def printUsage():
	print("Usage: ")
	print("webplayer.py {PATH}")
	print("Checks the directory for audio files and creates a js file listing those")

def checkInput():
	if len(sys.argv) == 2:
		checkDirectory(sys.argv[1])
	else:
		printUsage()

if __name__ == "__main__":
	try:
		checkInput()
	except KeyboardInterrupt:
		pass
