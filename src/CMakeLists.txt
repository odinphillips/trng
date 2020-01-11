cmake_minimum_required(VERSION 3.5)

set(SRCS
    SourcePrng.cpp
    SourceAudio.cpp
)

add_library(trng ${SRCS})
target_compile_options(trng PUBLIC -std=c++1y)
target_include_directories(trng PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)