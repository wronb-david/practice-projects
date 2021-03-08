var ff13pt = {data : {}};

ff13pt.data.game = {
	"name" : ""
};

ff13pt.data.players = new Array();
ff13pt.gameLoaded = false;

ff13pt.saveToFile = function saveToFile() {
	var text, dataURL, filename;
	text = JSON.stringify(ff13pt.data);
	dataURL = ff13pt.jsonToDataURL(text);
	if (ff13pt.gameLoaded) {
		filename = ff13pt.data.game.name + ".json";
	} else {
		filename = "Test.json";
	}
	ff13pt.download(dataURL, filename);
	ff13pt.elems.unsavedData.setAttribute("class", "hidden");
}

ff13pt.jsonToDataURL = function jsonToDataURL(jsonIn) {
	var prefix = "data:text/json,";
	//TODO convert jsonIn to valid DataURL
	return prefix + jsonIn;
}

// via https://stackoverflow.com/questions/3916191/download-data-url-file/15832662#15832662
ff13pt.download = function download(dataurl, filename) {
	var a = document.createElement("a");
	a.href = dataurl;
	a.setAttribute("download", filename);
	var b = document.createEvent("MouseEvents");
	b.initEvent("click", false, true);
	a.dispatchEvent(b);
	return false;
}

ff13pt.loadGame =function() {
	ff13pt.loadFromFile(); // data == loadedData
	ff13pt.elems.load.setAttribute("class", "hidden");
	ff13pt.elems.addPlayer.removeAttribute("class");
	ff13pt.gameLoaded = true;
}

// https://stackoverflow.com/questions/7346563/loading-local-json-file
ff13pt.loadFromFile = function loadFromFile() {
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
		fr.onload = ff13pt.parseData;
		fr.readAsText(file);
	}
}

ff13pt.parseData = function(e) {
	let lines = e.target.result;
	var loadedJson = JSON.parse(lines);
	ff13pt.data = loadedJson;
	document.title = "Fifa 13 Player Value Tracker - " + ff13pt.data.game.name;
	ff13pt.reloadDataPlayer();
};


ff13pt.pageLoad = function(event) {
	ff13pt.elems = {};

	// Fieldsets
	
	ff13pt.elems.start = document.getElementById("ff13Start");
	ff13pt.elems.load = document.getElementById("ff13Load");
	ff13pt.elems.create = document.getElementById("ff13Create");
	ff13pt.elems.addPlayer = document.getElementById("ff13AddPlayer");
	ff13pt.elems.updateValue = document.getElementById("ff13UpdateFinalVaue");

	// Inputs

	ff13pt.elems.gameName = document.getElementById("ff13GameName");
	ff13pt.elems.playerName = document.getElementById("ff13PlayerName");
	ff13pt.elems.playerValue = document.getElementById("ff13PlayerValue");
	ff13pt.elems.finalValue = document.getElementById("ff13FinalValue");

	ff13pt.elems.selPlayer = document.getElementById("ff13SelPlayer");
	
	// Table 
	ff13pt.elems.playerTable = document.getElementById("tPlayers");
	ff13pt.elems.playerTBody = document.getElementById("tbPlayers");

	// Other
	ff13pt.elems.unsavedData = document.getElementById("unsavedData");

	for (var key in ff13pt.elems) {
		if(!ff13pt.elems[key]){
			console.log("Could not find element >>" + key + "<<");
		}
	}
}

ff13pt.startCreate = function() {
	ff13pt.elems.start.setAttribute("class", "hidden");
	ff13pt.elems.create.removeAttribute("class");
}

ff13pt.startLoad = function() {
	ff13pt.elems.start.setAttribute("class", "hidden");
	ff13pt.elems.load.removeAttribute("class");
}

ff13pt.createGame = function() {
	var gName = ff13pt.elems.gameName;
	if (gName) {
		if(gName.value == "") {return;}

		ff13pt.data.game.name = gName.value;
		ff13pt.data.players = new Array();
		
		ff13pt.elems.create.setAttribute("class", "hidden");
		ff13pt.elems.addPlayer.removeAttribute("class");

		ff13pt.gameLoaded = true;
		
		document.title = "Fifa 13 Player Value Tracker - " + ff13pt.data.game.name;
		ff13pt.reloadDataPlayer();
	}
}

ff13pt.addPlayer = function() {
	var ePlayerName = ff13pt.elems.playerName;
	var ePlayerValue = ff13pt.elems.playerValue;
	if(!ePlayerName || !ePlayerValue) {
		console.log("addPlayer error::formElementnotFound \n");
		console.log("addPlayer::ePlayerName >>" + ePlayerName + "<<");
		console.log("addPlayer::ePlayerValue >>" + ePlayerValue + "<<");
		return;
	}

	const playerName = ePlayerName.value;
	const playerValue = ePlayerValue.value;

	if( playerName.trim() != "" && playerValue >= 0) {
		var newPlayer = {
			name : playerName,
			startingValue : playerValue,
			finalValue : playerValue,
			difference : 0,
			bSold : false
		};
		
		ff13pt.data.players.push(newPlayer);

		ff13pt.elems.unsavedData.removeAttribute("class");
		ff13pt.reloadDataPlayer();
	}
}

ff13pt.updateFinalValue = function () {
	var eFinalValue = ff13pt.elems.finalValue;
	var eSelPlayer = ff13pt.elems.selPlayer;
	if(!eFinalValue || !eSelPlayer) {
		console.log("updateFinalValue error::formElementnotFound \n");
		console.log("updateFinalValue::eFinalValue >>" + eFinalValue + "<<");
		console.log("updateFinalValue::eSelPlayer >>" + eSelPlayer + "<<");
		return;
	}

	var finalValue = eFinalValue.value
	var playerIndex = eSelPlayer.options[eSelPlayer.selectedIndex].value;
	var bPlayerExists = ff13pt.data.players[playerIndex] != undefined;
	
	if(finalValue >= 0 && bPlayerExists) {
		var thePlayer = ff13pt.data.players[playerIndex];
		thePlayer.finalValue = finalValue;
		thePlayer.bSold = true;
		thePlayer.difference = thePlayer.finalValue - thePlayer.startingValue;

		ff13pt.elems.unsavedData.removeAttribute("class");
		ff13pt.reloadDataPlayer();
	}

}

ff13pt.reloadData = function() {
	ff13pt.reloadDataPlayer();
}

ff13pt.reloadDataPlayer = function() {
	if(ff13pt.data.players.length > 0) {
		ff13pt.elems.playerTable.removeAttribute("class");
		ff13pt.elems.updateValue.removeAttribute("class");
		ff13pt.regenPlayerBody();
		ff13pt.regenPlayerSelect();
	}
}

ff13pt.clearElem = function(parent) {
	while(parent.firstChild) {
		parent.removeChild(parent.firstChild);
	}
}

ff13pt.regenPlayerBody = function() {
	var playerTBody = ff13pt.elems.playerTBody;
	ff13pt.clearElem(playerTBody);
	
	ff13pt.data.players.forEach((player, playerIndex) => {
		let row = document.createElement("tr");
		if(player.bSold) {
			row.setAttribute("class", "sold");
		} else {
			row.setAttribute("class", "notsold");
		}
		
		let nameCell = document.createElement("th");
		let nameTN = document.createTextNode(player.name);
		nameCell.appendChild(nameTN);
		row.appendChild(nameCell);

		let svCell = document.createElement("td");
		let svTextNode = document.createTextNode(player.startingValue);
		svCell.appendChild(svTextNode);
		row.appendChild(svCell);
		
		let fvCell = document.createElement("td");
		let fvTextNode = document.createTextNode(player.finalValue);
		fvCell.appendChild(fvTextNode);
		row.appendChild(fvCell);

		let diffCell = document.createElement("td");
		let diffTextNode = document.createTextNode(player.difference);
		diffCell.appendChild(diffTextNode);
		row.appendChild(diffCell);

		if (player.difference < 0) {
			diffCell.setAttribute("class", "soldAtLoss")
		}

		let soldCell = document.createElement("td");
		let text = player.bSold ? '\u2714': "X";
		let soldTextNode = document.createTextNode(text);
		soldCell.appendChild(soldTextNode);
		row.appendChild(soldCell)

		playerTBody.appendChild(row);
	});
}

ff13pt.regenPlayerSelect = function() {
	var selPlayer = ff13pt.elems.selPlayer;
	ff13pt.clearElem(selPlayer);
	
	var defoption = document.createElement("option");
	var defoptionTextNode = document.createTextNode("Select Player");
	defoption.setAttribute("value", "-1");
	defoption.setAttribute("disabled", "disabled");
	defoption.setAttribute("selected", "selected");
	defoption.appendChild(defoptionTextNode);
	
	selPlayer.appendChild(defoption)
	
	var validCount = 0

	ff13pt.data.players.forEach((player, playerIndex) => {
		if(!player.bSold) {
			let option = document.createElement("option");
			let optionTextNode = document.createTextNode(player.name);
			option.setAttribute("value", playerIndex);
			option.appendChild(optionTextNode);
		
			selPlayer.appendChild(option)

			validCount = validCount + 1;
		}
	});

	if (validCount == 0) {
		ff13pt.elems.updateValue.setAttribute("class", "hidden");
	}
}

window.addEventListener("load", ff13pt.pageLoad);