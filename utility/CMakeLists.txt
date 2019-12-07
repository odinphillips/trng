add_library(utility utility.cpp)
target_compile_options(utility PUBLIC -std=c++1y)
target_include_directories(utility PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)
