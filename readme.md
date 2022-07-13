# Terminal Renderer

## Info
* This repo contains a basic example of terminal rendering.
* C++ extension of the example of rotating torus demonstrated by a1k0n.
* Sphere and torus implemented, lines to come.

## Compilation/Installation
* Project uses CMake and should compile with standard c++ libraries.
* Shell should define $LINES and $COLUMNS, these need to be exported to environment variables.
* Either define before running your initial CMake or add the following to your .rc file:
```
export LINES=$LINES
export COLUMNS=$COLUMNS
```
