cmake_minimum_required(VERSION 3.14)

project(automatic-octo-spoon)

set(CMAKE_CXX_FLAGS "--std=c++11")

aux_source_directory(src SOURCES)

add_library(opt-entity STATIC ${SOURCES})
target_include_directories(splat-entity PUBLIC ./include)