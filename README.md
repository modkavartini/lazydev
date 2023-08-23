# lazydev
a skin to help make skins

## function
lazydev detects the `.ini`, `.inc`, `.lua` or `.ps1` file that you're editing and refreshes the appropriate active rainmeter skin(s) upon ctrl+s

## preview
### editor.ini
detected a single skin:

![active](https://github.com/modkavartini/lazydev/assets/81793953/ef654368-4bc1-4397-b1ee-f5d06fedb03b)

detected more than one skins:

![many](https://github.com/modkavartini/lazydev/assets/81793953/573df7af-9c27-44a9-8e18-906ec065facf)

did not detect any active skins:

![ded](https://github.com/modkavartini/lazydev/assets/81793953/1d0e9b5e-45d2-4853-aad7-bbae8d606ddd)

### focus.ini
i have included a simpler variant which selects the skin when you ctrl+click on it. can be used if the main variant is not meeting your needs.

### note
* lazydev detects any active configs under the rootConfig of the opened `@include` file, irrespective of whether the file is `@include`d in the detected skin or not.
* lazydev can only detect the files opened in notepad/notepad++/visual studio code by default. if you use any other editor you can [add it](https://github.com/modkavartini/lazydev/blob/main/editor.ini#L93) by editing the skin file.

### credits
#### plugins:
* [getActiveTitle](https://forum.rainmeter.net/viewtopic.php?t=33146) by [jsmorley](https://github.com/jsmorley)
* [hotkey](https://github.com/brianferguson/HotKey.dll) by [brianferguson](https://github.com/brianferguson)
* [isFullScreen](https://forum.rainmeter.net/viewtopic.php?t=28305) by [jsmorley](https://github.com/jsmorley)
* [powerShellRM](https://forum.rainmeter.net/viewtopic.php?t=29095) by [khanhas](https://github.com/khanhas)
