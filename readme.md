# Terminal Renderer

## Info
* This repo contains a small 3d rendering engine for the terminal.
* Started as a C++ extension of the example of rotating torus demonstrated by a1k0n.
* Torus, sphere, cube, and cylinder originally implemented with a surface iteration model.
* Currently under breaking refactors, moving over to use data from .obj and .stl files.

## Compilation/Installation
* CMake file provided for compilation. 
* The only dependencies are standard c++ libraries.
* Shell should define $LINES and $COLUMNS, these need to be exported to environment variables.
* Either define before running your initial CMake or add the following to your shells rc file:
```
export LINES=$LINES
export COLUMNS=$COLUMNS
```
