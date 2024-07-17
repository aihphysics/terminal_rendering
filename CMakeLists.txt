## Donut and basic rendering attempt c++

cmake_minimum_required(VERSION 3.23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project( terminal_renderer )

include_directories(inc)

set( sources src/main.cxx src/screen.cxx src/vec.cxx src/obj.cxx )
add_executable( rend ${sources})
add_compile_options(-std=c++11 -Werror -Wall -pedantic -Wextra -O2 -pthread )


IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json" )
	EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json )
ELSE()
	EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E ${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json )
ENDIF()
