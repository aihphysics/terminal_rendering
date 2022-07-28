# Terminal Renderer

## Info
* This repo contains an attempt to build a 3d rendering engine for the terminal.
* C++ extension of the example of rotating torus demonstrated by a1k0n.
* Torus, sphere, cube, and cylinder implemented with a surface iteration model.

## Compilation/Installation
* Project uses CMake and should compile with standard c++ libraries.
* Shell should define $LINES and $COLUMNS, these need to be exported to environment variables.
* Either define before running your initial CMake or add the following to your .rc file:
```
export LINES=$LINES
export COLUMNS=$COLUMNS
```
