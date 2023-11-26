cmake_minimum_required(VERSION 3.22)
project(game-engine)

include(FetchContent)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.6.x
	)

# REMOVE THE COMMENT TO DOWNLOAD SFML IF NOT: take a lil bit of time
# FetchContent_MakeAvailable(SFML) 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ETIB_GRAPHICAL_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/plugins/libgraphical-sfml.so)


file(GLOB_RECURSE GAME_ENGINE_SOURCES "src/*.cpp")
include_directories(include)

# create a shared library
add_library(game-engine SHARED ${GAME_ENGINE_SOURCES})
# copy the library into a folder
add_custom_command(TARGET game-engine POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:game-engine> ${CMAKE_SOURCE_DIR}/../libgraphical-engine.so
	)
target_link_libraries(game-engine sfml-graphics sfml-window sfml-system sfml-audio)
target_compile_options(game-engine PRIVATE -g3 -ggdb)

