# Google test lib
add_library(gtest ${GTEST_DIR}/src/gtest-all.cc)
target_include_directories(gtest PUBLIC ${GTEST_DIR}/include ${GTEST_DIR})

# foobar test app
add_executable(foobar foobar.cpp)
target_link_libraries(foobar gtest)
