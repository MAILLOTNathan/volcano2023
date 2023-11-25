cmake_minimum_required(VERSION 3.22)
project(libsfml)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories(include)

add_library(graphical-sfml SHARED ${SOURCES})
add_custom_command(TARGET graphical-sfml POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:graphical-sfml> ${CMAKE_SOURCE_DIR}/../libgraphical-sfml.so)
