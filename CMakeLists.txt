cmake_minimum_required(VERSION 3.22)
project(volcano)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")

set(ETIB_SHARED_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/libgame-engine.so)

include_directories(include)

add_executable(volcano ${SOURCES})
target_link_libraries(volcano ${ETIB_SHARED_LIB})

