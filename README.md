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

This project provides a very simple GUI for the command line tool youtube-dl. It also allows the user to save a "command queue" for the command line tool as JSON file.

* apply WPF/MVVM knowledge using MVVM Cross
* learn how to call an external process without locking the UI thread.
* learn how to use .net's JSON library to save / load data.

Pitfalls fallen into:

* Observable collections don't like being updated from another thread (at least prior to .net 4.5)
(Tried to use a callback to pipe the output of youtube-dl into the collection)

Added a checkbox allow the options text to remain after starting a direct download / adding a task to the queue.

## XUnitTesting

This project acts as a "playground" to experiment with the different features of the XUnit testing library. I'm also using this project to implement some of the common design patterns (Currently: Singleton & Decorator).

## Currently Looking into ...

* Design Pattern refresher
* Design Principles: SOLID
  - Single Responsibility Principle
  - Open Close Principle
  - Liskov Substitution Principle
  - Interface Segregation Principle
  - Dependency Inversion Principle
* Unit Testing: Mocking
* Storing binary data in SQL-Databases