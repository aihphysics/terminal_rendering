## Donut and basic rendering attempt c++

cmake_minimum_required(VERSION 3.23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(donut)

include_directories(inc)

set(src src/main.cxx src/sphere.cxx src/light.cxx)
add_executable( donut ${src})
add_compile_options(-std=c++11 -Werror -Wall -pedantic -Wextra -O3)


IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json" )
	EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json )
ELSE()
	EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E ${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json )
ENDIF()
