cmake_minimum_required(VERSION 3.5)

# foobar test app
add_executable(TestSourcePrng TestSourcePrng.cpp)
target_link_libraries(TestSourcePrng gtest trng utility)
