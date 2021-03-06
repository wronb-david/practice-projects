# David's Practice Projects

While I'm learning C#, I'm working on these projects. This repository acts as a public storage for these.
Some of my projects in other languagues are also found here.

## (C#, Harmony) ONI Mod: AdjustedFoodDisplay

The initial project that brought me to C#: A mod for the game "Oxygen Not Included".
It uses the harmony library, that is included with the game, to change how the base game [1] displays the total calories available to the colony. By default the game counts all available food items and displays ther total calories at the top of the screen, while also providing the same number on the right edge of the screen as part of the resource display.

The mod aims to adjust the number at the top of the screen, so it only accounts for the food that at least one colonist is permitted to eat. While these values will initially overlap, the will diverge as the game progresses, when the player begins to disallow the consumption of raw and low quality food. The number on the resource display remains unchanged, so both values are available to the player at any given time.

To achieve this the mod uses harmony's postfix hooks to latch onto 3 functions:
* The refresh function of the calorie display - to update the text.
* The food permission change for the colonists - to track permission changes.
* The activation of the food display - to trigger the initial update of the display.

The last one is a crude helper as finding a good trigger, that triggers once after the game is completely loaded is hard, because certain data are only fully populated after unpausing the game after a load.

[1] To support the multi-colony nature of first DLC adjustments may have to be made.

## (C#) YTDL GUI 

After following Tim Corey's [tutorial](https://www.youtube.com/playlist?list=PLLWMQd6PeGY3QEHCmCWaUKNhmFFdIDxE8) on WPF/MVVM, my goal for this project was to move past the shell of the typical tutorial project, while also solving a "real" issue.

This project provides a very simple GUI for the command line tool youtube-dl. It will also save the queued commands in JSON file, which is loaded upon starting the application. 

More details in the [project's own markdown file](YTDL%20GUI/readme.md)

## (C#) XUnitTesting

This project acts as a "playground" to experiment with the different features of the XUnit testing library. I'm also using this project to implement some of the common design patterns (Currently: Singleton & Decorator).

## (C++) DysonSphereProgram Calculator (Added: 2021-03-08) [WIP]

This is a small C++17 console application parses two command line arguments (color, rate) and then prints the list of resources required to produce the science matrices of the given color at the given rate.

[Update 2021-03-11] The calculations for crafting blue science (Electromagnetic Matrix) is now implemented, crafting recipes & item data for the remaining colors have to be added.

* The Item struct now just holds a string. 
* The Crafting recipes are now their own struct, as there are recipes with multiple source materials and products - as part of the item struct these were initially limited to just multiple source materials as they were tied to item in question.


## (Web) Player Value Tracker

One of my slightly older projects. A very simple tracker for player values in Fifa 13. Mainly to experiment with data urls, to be able to save (download) the existing data into a json file, and the Web API class FileReader, to be able to load that json data back in.


## (Web) Audio Player (Added: 2021-03-16)

Testing HTML5's audio element by creating a rather minimalistic HTML5 / javascript based audio player. The project uses a small python script to generate the audio file library for the player. The python script uses eyeD3 to extract the tag information from the audio files.

---

## Currently Looking into ...

A list of topics, that I'm currently looking into - or have looked into recently - can be found [here](docs/learning.md).

## Watchlist etc.

A list of programming related blogs I read, channels I watch and podcasts I listen to can be found [here](docs/watchlist.md)