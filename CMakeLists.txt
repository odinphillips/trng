cmake_minimum_required(VERSION 3.5)

project(libtrng)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/googletest/googletest)

add_subdirectory(3rdParty)
add_subdirectory(scratch/portaudio_demo)
add_subdirectory(utility)
add_subdirectory(test)
add_subdirectory(src)
