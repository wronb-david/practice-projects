# David's Practice Projects

While I'm learning C#, I'm working on these projects. This repository acts as a public storage for these.

## ONI Mod: AdjustedFoodDisplay

The initial project that brought me to C#: A mod for the game "Oxygen Not Included".
It uses the harmony library, that is included with the game, to change how the base game [1] displays the total calories available to the colony. By default the game counts all available food items and displays ther total calories at the top of the screen, while also providing the same number on the right edge of the screen as part of the resource display.

The mod aims to adjust the number at the top of the screen, so it only accounts for the food that at least one colonist is permitted to eat. While these values will initially overlap, the will diverge as the game progresses, when the player begins to disallow the consumption of raw and low quality food. The number on the resource display remains unchanged, so both values are available to the player at any given time.

To achieve this the mod uses harmony's postfix hooks to latch onto 3 functions:
* The refresh function of the calorie display - to update the text.
* The food permission change for the colonists - to track permission changes.
* The activation of the food display - to trigger the initial update of the display.

The last one is a crude helper as finding a good trigger, that triggers once after the game is completely loaded is hard, because certain data are only fully populated after unpausing the game after a load.

[1] To support the multi-colony nature of first DLC adjustments may have to be made.

## YTDL GUI 

After following Tim Corey's [tutorial](https://www.youtube.com/playlist?list=PLLWMQd6PeGY3QEHCmCWaUKNhmFFdIDxE8) on WPF/MVVM, my goal for this project was to move past the shell of the typical tutorial project, while also solving a "real" issue.

This project provides a very simple GUI for the command line tool youtube-dl. It will also save the queued commands in JSON file, which is loaded upon starting the application. 

More details in the [project's own markdown file](YTDL%20GUI/readme.md)



## XUnitTesting

This project acts as a "playground" to experiment with the different features of the XUnit testing library. I'm also using this project to implement some of the common design patterns (Currently: Singleton & Decorator).

## Currently Looking into ...

A list of topics, that I'm currently looking into - or have looked into recently - can be found [here](docs/learning.md).

## Watchlist etc.

A list of programming related blogs I read, channels I watch and podcasts I listen to can be found [here](docs/watchlist.md)