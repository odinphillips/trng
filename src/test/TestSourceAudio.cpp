#include <stdio.h>

#include <fstream>
#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "ent_fields.h"
#include "utility.h"
#include "SourceAudio.h"

using namespace std;

TEST(SourceAudio, OpenClose) {
    SourceAudio src;
    src.open();
    src.close();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
