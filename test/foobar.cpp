#include <iostream>

#include "gtest/gtest.h"

static int add(int a, int b) {
    return a + b;
}

TEST(AddTest, HandlesZeroInput) {
    EXPECT_EQ(add(0, 0), 0);
}

// Example failing test
TEST(AddTest, FakeFail) {
    EXPECT_EQ(add(1, 1), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
