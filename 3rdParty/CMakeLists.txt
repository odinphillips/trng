cmake_minimum_required(VERSION 3.5)

# Google test lib
add_library(gtest ${GTEST_DIR}/src/gtest-all.cc)
target_compile_options(gtest PUBLIC -std=c++11)
target_link_libraries(gtest pthread)
target_include_directories(gtest PUBLIC ${GTEST_DIR}/include ${GTEST_DIR})

add_subdirectory(portaudio EXCLUDE_FROM_ALL)

