cmake_minimum_required(VERSION 3.28)
set(CMAKE_GENERATOR "Ninja")

project(areas)

set(CXX_STANDARD 23)
add_compile_options(-Wall -Wpedantic)

find_package(fmt)
add_subdirectory(src)