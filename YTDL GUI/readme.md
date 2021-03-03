## YTDL GUI 

After following Tim Corey's [tutorial](https://www.youtube.com/playlist?list=PLLWMQd6PeGY3QEHCmCWaUKNhmFFdIDxE8) on WPF/MVVM, my goal for this project was to move past the shell of the typical tutorial project, while also solving a "real" issue.

This project provides a very simple GUI for the command line tool youtube-dl. It will also save the queued commands in JSON file, which is loaded upon starting the application.

Goals:
* apply WPF/MVVM knowledge using MVVM Cross
* learn how to call an external process without locking the UI thread.
* learn how to use .net's JSON library to save / load data.

Pitfalls fallen into:

* Observable collections don't like being updated from another thread (at least prior to .net 4.5)
(Tried to use a callback to pipe the output of youtube-dl into the collection)

Added a checkbox allow the options text to remain after starting a direct download / adding a task to the queue.

### Update (2021-02-27) - Implementing the SOLID principle

Changed the concrete types (YTDLHandler, JSONHandler, VideoDownloadModel) to Interfaces to decouple the ViewModel from their implementations. A **factory** now builds these corresponding objects. 


Initially this was the only point where the interfaces were mapped to the concrete types until a new Problem arose: 

**(De-)serializing interfaces with System.Text.Json - How does it work?**

Via:
* https://stackoverflow.com/questions/58373915/serialize-objects-implementing-interface-with-system-text-json
* https://khalidabuhakmeh.com/serialize-interface-instances-system-text-json

Solution: Provide a JsonConverter for IVideoDownloadModel. Implemented that VideoDownloadModelConverter, so the JSONHandler can now (de)serialize IVideoDownloadModel, sadly that converter tightly couples the IVideoDownloadModel interface to the VideoDownloadModel implementation.

Alternative solution: Not using the interfaces for the raw data (model) types as those are unlikely to be replaced and would need special treatment in that case anyways.
