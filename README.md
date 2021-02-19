# practice-projects

This repository acts as a storage for my practice projects. As part of learning C# I have been working on a couple small projects.

## ONI Mod: AdjustedFoodDisplay

The initial project that brought me to C#: A mod for the game "Oxygen Not Included".
It uses the harmony library, that is included with the game, to change how the (base) game [1] displays the avaiable calories. By default the game counts all available food and displays this as total available calories at the top of the screen, while also providing the same number on the right of the screen as part of the header for the food category of the resource display.

The mod aims to adjust the number at the top of the screen, so it only accounts for the food that at least one colonist is permitted to eat - usually excluding "raw" & low quality food as the game progresses. The number on the resource display remains unchanged.

To achieve this the mod uses harmony's postfix hooks to latch onto 3 functions:
* The refresh function of the calorie display - to update the text.
* The food permission change for the colonists - to track permission changes.
* The activation of the food display - to trigger the initial update of the display.

The last one is a crude helper as finding a good trigger, that triggers once after the game is completely loaded is hard, because certain data are only fully populated after unpausing the game after a load.

[1] To support the multi-colony nature of first DLC, adjustments may have to be made.

## YTDL GUI 

The goal for this project was to move past the shell of the WPF tutorial projects, while also solving a "real" issue.

This project provides a very simple GUI for the command line tool youtube-dl. It also allows the user to save a "command queue" for the command line tool as JSON file.

* apply WPF/MVVM knowledge
* learn how to use .net's JSON library to save / load data.
* learn how to call an external process - ideally without locking the UI thread.

