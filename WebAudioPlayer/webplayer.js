var webplayer = {
	library : {
		data : {}
	},
	playlist : { 
		data : { songs : [],
			name : "playlist"},
		isLoaded : false,
		hasName : false
	},
	player : {
		randomize : false,
		repeatSong : false,
		repeatList : true,
		currentIndex : -1,
		isPaused : false,
		isStopped : true
	}
};

webplayer.playlist.saveToFile = function saveToFile() {
	var text, dataURL, filename;
	text = JSON.stringify(webplayer.playlist.data);
	dataURL = webplayer.playlist.jsonToDataURL(text);
	if (webplayer.playlist.hasName) {
		filename = webplayer.playlist.data.name + ".json";
	} else {
		filename = "playlist.json";
	}
	webplayer.playlist.download(dataURL, filename);
}

webplayer.playlist.jsonToDataURL = function jsonToDataURL(jsonIn) {
	var prefix = "data:text/json,";
	//TODO convert jsonIn to valid DataURL
	return prefix + jsonIn;
}

// via https://stackoverflow.com/questions/3916191/download-data-url-file/15832662#15832662
webplayer.playlist.download = function download(dataurl, filename) {
	var a = document.createElement("a");
	a.href = dataurl;
	a.setAttribute("download", filename);
	var b = document.createEvent("MouseEvents");
	b.initEvent("click", false, true);
	a.dispatchEvent(b);
	return false;
}

webplayer.playlist.updateName = function() {
	var plName = webplayer.elems.playlistName.value;
	if(plName.trim() != "") {
		webplayer.playlist.data.name = plName.trim();
		webplayer.playlist.hasName = true;
	} else {
		webplayer.playlist.hasName = false;
	}
}

webplayer.playlist.load =function() {
	webplayer.playlist.loadFromFile(); // data == loadedData
	webplayer.playlist.isLoaded = true;
	console.log("LOAD");
	webplayer.genereatePlaylistTable();
	webplayer.playlist.show();
}

webplayer.playlist.loadFromFile = function loadFromFile() {
	var input, file, fr;
	if (typeof window.FileReader !== 'function') {
		console.log("Browser doesn't support the File-API");
		return;
	}
	input = document.getElementById('fileInput');
	if (!input) {
		console.log("Required element >>fileInput<< could not be found.");
	}
	else if (!input.files) {
		console.log("Required `files` property of file inputs is not supported.");
	}
	else if (!input.files[0]) {
		console.log("Pressed load without selecting a file first.");
	}
	else {
		file = input.files[0];
		fr = new FileReader();
		fr.onload = webplayer.playlist.parseData;
		fr.readAsText(file);
	}
}

webplayer.playlist.parseData  = function(e) {
	let lines = e.target.result;
	var loadedJson = JSON.parse(lines);
	webplayer.playlist.data = loadedJson;

};

webplayer.playlist.clear = function() {
	webplayer.playlist.data = {};
	webplayer.playlist.data.songs = new Array();
	webplayer.playlist.hide();
}

webplayer.playlist.removeSong = function(index) {
	webplayer.playlist.data.songs.splice(index, 1);
	if(webplayer.playlist.data.songs.length == 0) {
		webplayer.clearElem(webplayer.elems.playlistTBody);
		webplayer.playlist.hide();
	} else {
		webplayer.genereatePlaylistTable();
	}
}

webplayer.playlist.hide = function() {
	if(webplayer.elems.playlistTable) {
		webplayer.elems.playlistTable.setAttribute("class", "hidden");
	}
	if(webplayer.elems.save) {
		webplayer.elems.save.setAttribute("class", "hidden");
	}
}

webplayer.playlist.show = function(){
	if(webplayer.playlist.data.songs.length > 0) {
		if(webplayer.elems.playlistTable) {
			webplayer.elems.playlistTable.removeAttribute("class");
		}
		if(webplayer.elems.save){
			webplayer.elems.save.removeAttribute("class");
		}
	}
}

webplayer.clearElem = function(parent) {
	while(parent.firstChild) {
		parent.removeChild(parent.firstChild);
	}
}

webplayer.genereatePlaylistTable = function() {
	var playlistBody = webplayer.elems.playlistTBody;
	webplayer.clearElem(playlistBody)

	var data = webplayer.playlist.data;
	data.songs.forEach((song, songIndex) => {
		let row = document.createElement("tr");
		
		// Title
		let titleCell = document.createElement("th");
		let titleTN = document.createTextNode(song.title);
		titleCell.appendChild(titleTN);
		row.appendChild(titleCell);
		// Artist
		let artistCell = document.createElement("th");
		let artistTN = document.createTextNode(song.artist);
		artistCell.appendChild(artistTN);
		row.appendChild(artistCell);
		// Album
		let albumCell = document.createElement("th");
		let albumTN = document.createTextNode(song.album);
		albumCell.appendChild(albumTN);
		row.appendChild(albumCell);
		
		// Actions
		let actionCell = document.createElement("th");
		let playSpan = document.createElement("span");
		let playSpanTN = document.createTextNode("Play");
		playSpan.addEventListener("click", (ev) => {webplayer.player.playSongWithIndex(songIndex);});
		playSpan.appendChild(playSpanTN);
		actionCell.appendChild(playSpan);

		let spacingTN =  document.createTextNode(" - ");
		actionCell.appendChild(spacingTN);

		let removeSpan = document.createElement("span");
		let removeSpanTN = document.createTextNode("Remove");
		removeSpan.addEventListener("click", (ev) => {webplayer.playlist.removeSong(songIndex);});
		removeSpan.appendChild(removeSpanTN);
		actionCell.appendChild(removeSpan);

		row.appendChild(actionCell);
		
		playlistBody.appendChild(row);
	});
}

webplayer.genereateLibraryTable = function(data, bUseInnerIndex) {
	var libraryBody = webplayer.elems.libraryTBody;
	webplayer.clearElem(libraryBody)

	var counter = 1;
	data.forEach((song, songIndex) => {
		let actualIndex = songIndex;
		if(bUseInnerIndex) {
			actualIndex = song.index;
		}
		let row = document.createElement("tr");

		// Counter Cell
		let counterCell = document.createElement("td");
		let counterTN = document.createTextNode(counter);
		counter = counter + 1;
		counterCell.appendChild(counterTN);
		row.appendChild(counterCell);

		// Title
		let titleCell = document.createElement("th");
		titleCell.setAttribute("title", "File Path: " + song.path)
		let titleTN = document.createTextNode(song.title);
		titleCell.appendChild(titleTN);
		row.appendChild(titleCell);
		// Artist
		let artistCell = document.createElement("th");
		let artistTN = document.createTextNode(song.artist);
		artistCell.appendChild(artistTN);
		row.appendChild(artistCell);
		// Album
		let albumCell = document.createElement("th");
		let albumTN = document.createTextNode(song.album);
		albumCell.appendChild(albumTN);
		row.appendChild(albumCell);
		
		// Actions
		let actionCell = document.createElement("th");
		let playSpan = document.createElement("span");
		let playSpanTN = document.createTextNode("Play Now");
		playSpan.addEventListener("click", (ev) => {
			let plIndex = webplayer.playlist.addSong(actualIndex);
			if(plIndex > -1) {
				webplayer.player.playSongWithIndex(plIndex);
			}
		});
		playSpan.appendChild(playSpanTN);
		actionCell.appendChild(playSpan);

		let spacingTN =  document.createTextNode(" - ");
		actionCell.appendChild(spacingTN);

		let enqueueSpan = document.createElement("span");
		let enqueueSpanTN = document.createTextNode("Enqueue");
		enqueueSpan.addEventListener("click", (ev) => {
			let plIndex = webplayer.playlist.addSong(actualIndex);
		});
		enqueueSpan.appendChild(enqueueSpanTN);
		actionCell.appendChild(enqueueSpan);

		row.appendChild(actionCell);
		
		libraryBody.appendChild(row);
	});
}

webplayer.playlist.addSong = function(songIndex) {
	song = webplayer.library.data.songs[songIndex];
	if(song){
		webplayer.playlist.data.songs.push(song);
		var index = webplayer.playlist.data.songs.length - 1;
		webplayer.genereatePlaylistTable();
		webplayer.playlist.show();
		return index;
	}
	return -1;
}

webplayer.library.search = function() {
	var searchText = webplayer.elems.songSearchText.value;
	var data = new Array();
	var bUseInnerIndex = false;
	if(searchText.trim() == "") {
		data = webplayer.library.data.songs;
	} else {
		// Match Songs to search text based on title, artist and album
		searchText = searchText.toLowerCase();
		webplayer.library.data.songs.forEach((song, songIndex) => {
			if(song.title.toLowerCase().includes(searchText) || song.artist.toLowerCase().includes(searchText) 
				|| song.album.toLowerCase().includes(searchText) || song.path.toLowerCase().includes(searchText)) {
				song.index = songIndex;
				data.push(song);
			}
		});
		bUseInnerIndex = true;
	}
	if(data.length > 0) {
		webplayer.genereateLibraryTable(data, bUseInnerIndex);
	} else {
		webplayer.clearElem(webplayer.elems.libraryTBody);
	}
};

webplayer.player.playPause = function() {
	if(webplayer.player.isPaused) {
		webplayer.player.play();
		webplayer.player.isPaused = false;
	} else {
		webplayer.player.pause();
		webplayer.player.isPaused = true;
	}
}

webplayer.player.play = function(){
	if(webplayer.player.isStopped) {
		webplayer.player.isStopped = false;
		const INDEX = webplayer.player.getNextSongIndex();
		webplayer.player.playSongWithIndex(INDEX);
	} else {
		webplayer.elems.audio.play();
	}
};

webplayer.player.playSongWithIndex = function(index) {
	if(index >= 0) {
		var song = webplayer.playlist.data.songs[index];
		if(song) {
			var path = song.path.replaceAll("\\", "/");
			path = encodeURI("file:///" + path);
			webplayer.elems.audio.src = path;
			webplayer.player.currentIndex = index;
			
			var promise = webplayer.elems.audio.load();
		}
	}
}

webplayer.player.pause = function(){
	webplayer.elems.audio.pause();
};

webplayer.player.stop = function() {
	webplayer.elems.audio.pause();
	webplayer.elems.audio.currentTimte = 0;
	webplayer.player.isStopped = true;
};

webplayer.getRandomIndex = function(start, end) {
	return Math.floor(Math.random() * (end - start + 1) + start);
};

webplayer.player.getNextSongIndex = function(){
	const COUNT = webplayer.playlist.data.songs.length;
	const OLD = webplayer.player.currentIndex;
	const CURRENT = (OLD <= (COUNT - 1)) ? OLD : (COUNT - 1);
	if(!webplayer.player.repeatSong) {
		if(webplayer.player.randomize) {
			// get a random ID between [0, maxIndex] where ID != currentIndex;
			if (COUNT == 1) { // Only one song nothing to randomize
				return 0;
			} else if  (COUNT == 2) { // Number of "other" songs == 1, still nothing to randomize
				return (CURRENT == 1) ? 0 : 1;
			} else { // 3 or more songs in the list
				var targetIndex = CURRENT;
				while(targetIndex == CURRENT) {
					targetIndex = webplayer.getRandomIndex(0, COUNT - 1);
				}
				return targetIndex
			}
		} else {
			if(CURRENT == COUNT - 1) {
				if(webplayer.player.repeatList) {
					return 0 // Start at the beginning of the list.
				} else {
					return -1; // Stop
				}
			} else {
				return 1 + CURRENT; // Play the next song in the list.
			}
		}
	} else {
		return webplayer.player.currentIndex;
	}
};

webplayer.player.setRandom = function() {
	var elem = webplayer.elems.checkBoxRandom;
	const isChecked = elem.checked;
	if(isChecked) {
		webplayer.player.randomize = true;
	} else {
		webplayer.player.randomize = false;
	}
};

webplayer.player.setRepeat = function(bRepeatSong, bRepeatList) {
	if(bRepeatSong && bRepeatList) {
		console.log("Error: setting Repeat both values are set to true")
	} else {
		if(!bRepeatSong && !bRepeatList) { // Repeate = None
			webplayer.player.repeatSong = false;
			webplayer.player.repeatList = false;
			//console.log("Test RNone")
		} else if(bRepeatSong) {
			webplayer.player.repeatSong = true;
			webplayer.player.repeatList = false;
			//console.log("Test RSong")
		} else {
			webplayer.player.repeatSong = false;
			webplayer.player.repeatList = true;
			//console.log("Test RList")
		}
	}
};

webplayer.pageLoad = function(event) {
	webplayer.findHTMLElements();
	if (webplayer.library.data.songs.length > 0) {
		webplayer.setLibraryVisibility(true);
		webplayer.genereateLibraryTable(webplayer.library.data.songs, false);
	}
	webplayer.hookUpAudioElement();
	webplayer.player.setVolume();
}

webplayer.findHTMLElements = function findHTMLElements() {
	webplayer.elems = {};

	// Audio Element
	webplayer.elems.audio = document.getElementById("audioPlayer");
	// Search Form
	webplayer.elems.searchForm = document.getElementById("formSearch");

	// Fieldsets
	webplayer.elems.load = document.getElementById("playlistLoad");
	webplayer.elems.save = document.getElementById("playlistSave");

	// Inputs
	webplayer.elems.playlistName = document.getElementById("playlistFileName");
	webplayer.elems.songSearchText = document.getElementById("songSearch");
	webplayer.elems.checkBoxRandom = document.getElementById("cbRandom");
	webplayer.elems.volumeSlider = document.getElementById("audioVolume");
	
	// Tables
	webplayer.elems.playlistTable = document.getElementById("tPlaylist");
	webplayer.elems.playlistTBody = document.getElementById("tbPlaylist");
	webplayer.elems.libraryTable = document.getElementById("tLibrary");
	webplayer.elems.libraryTBody = document.getElementById("tbLibrary");

	// Spans
	webplayer.elems.volumeSpan = document.getElementById("volumeValue");

	for (var key in webplayer.elems) {
		if(!webplayer.elems[key]){
			console.log("Could not find element >>" + key + "<<");
		}
	}
}

webplayer.setLibraryVisibility = function setLibraryVisibility(bState) {
	if(webplayer.elems.searchForm && webplayer.elems.libraryTable) {
		if(bState) {
			webplayer.elems.searchForm.removeAttribute("class");
			webplayer.elems.libraryTable.removeAttribute("class");
		} else {
			webplayer.elems.searchForm.setAttribute("class", "hidden");
			webplayer.elems.libraryTable.setAttribute("class", "hidden");
		}
	}
}

webplayer.hookUpAudioElement = function() {
	webplayer.elems.audio.addEventListener("ended", (event) => {
		webplayer.player.playbackEnded();
	});
	webplayer.elems.audio.addEventListener("loadend", (event) => {
		webplayer.player.loadended();
	});
	
	webplayer.elems.audio.addEventListener("canplaythrough", (event) => {
		webplayer.player.loadended();
	});
};

webplayer.player.playbackEnded = function(){
	const INDEX = webplayer.player.getNextSongIndex();
	webplayer.player.playSongWithIndex(INDEX);
};

webplayer.player.loadended = function() {
	webplayer.elems.audio.play();
}

webplayer.player.setVolume = function() {
	var slider = webplayer.elems.volumeSlider;
	var player = webplayer.elems.audio;
	var span = webplayer.elems.volumeSpan;
	if(slider && player) {
		var vol = slider.value;
		vol = vol / 100;
		player.volume = vol;

		webplayer.clearElem(span);
		volTN = document.createTextNode(slider.value + " / 100");
		span.appendChild(volTN);
	}
}


window.addEventListener("load", webplayer.pageLoad);