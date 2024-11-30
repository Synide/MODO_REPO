# Modo plug-in Software Developer Kit
The Modo Plug-in Software Developer Kit provides an application programming interface (API) and numerous source code samples that enable developers to read and write Modo scene, image, and movie files, introduce new commands and items into Modo, as well as plug-in scripting support.

The Modo SDK is based on COM, with C++ wrappers for many of the published APIs, and is available for Mac OS X, Windows 64-bit and Linux versions of Modo.

## What you can do with the Modo SDK
- Export data from Modo into the rest of your pipeline or tool suite (e.g. game engine)
- Control how Modo data looks to your application, for seamless downstream use in your asset pipeline
- Dump the contents of an LXO file into human-readable form
- Import data from another application into Modo. Read a proprietary in-house format or tackle an industry standard format
- Copy the contents of one LXO to another, applying custom operations as needed
- Introduce new procedural textures into Modo like pudding or boiling mud
- Add new Commands to Modo that execute native C++-based actions
- Introduce new types of geometry into Modo like nuts and bolts and screws
- Create new tools for Modo users that provide new ways to create and edit geometry
- Add new Replicator point generators to Modo. For example, you could create a condensation plug-in that places replicators, as you’d see on a sweating drinking glass
- Design innovative new ways for users to pick colors in Modo


## Building the samples

The Modo Samples come with [CMake](https://cmake.org/) scripts and not IDE-specific project/solution files.

### Visual Studio 2022 _(and later)_
This IDE has support for opening a directory with a CMakeLists.txt file and auto-configuring. More information can be found at:
 - [microsoft.com](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170#ide-integration)
 
### Visual Studio Code
This IDE has support for opening a directory with a CMakeLists.txt file and auto-configuring. More information can be found at:
 - [ms-vscode.cmake-tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
 - [twxs.cmake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake)

### Using CMake-Gui
 - Launch CMake-Gui
 - Use "Browse Source..." to find the Modo Samples source code.
 - Use "Browse Build..." to find a directory that you'd like to build into.
 - Press Configure and choose your preferred generator.

### Command Line
 - Open a terminal / command prompt.
 - Create a directory that you'd like to build into and navigate into it.
 - Run `cmake` by directing it to the source code.

Example
```
  mkdir modo-samples
  cd modo-samples
  cmake /path/to/modo/samples
  cmake --build . 
```
