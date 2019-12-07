cmake_minimum_required(VERSION 3.5)

# foobar test app
add_executable(foobar foobar.cpp)
target_link_libraries(foobar gtest)
