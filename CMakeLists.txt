cmake_minimum_required(VERSION 3.22)
project(volcano)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")

set(ETIB_SHARED_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/game-engine/libgame-engine.so)
set(ETIB_GRAPHICAL_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/game-engine/plugins/libgraphical-smfl.so)

include_directories(include)
include_directories(lib/game-engine/include)
include_directories(lib/game-engine/plugins/sfml/include)

add_executable(volcano ${SOURCES})
target_link_libraries(volcano ${ETIB_SHARED_LIB})

