## Donut and basic rendering attempt c++

cmake_minimum_required(VERSION 3.23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(term_renderer)

include_directories(inc)

set(lines $ENV{LINES})
set(columns $ENV{COLUMNS})
set(src src/main.cxx src/sphere.cxx src/torus.cxx src/light.cxx src/renderable.cxx src/screen.cxx)
add_executable( t_rend ${src})
add_compile_options(-std=c++11 -Werror -Wall -pedantic -Wextra -O3 )
add_definitions(-Dscreen_width=${columns} -Dscreen_height=${lines})
##message( LINES ${lines} )
##message( COLUMNS ${columns} )


IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json" )
	EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json )
ELSE()
	EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E ${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json )
ENDIF()
