#include <stdio.h>

#include <fstream>
#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "ent_fields.h"
#include "utility.h"
#include "SourcePrng.h"

using namespace std;

static int add(int a, int b) {
    return a + b;
}

TEST(AddTest, HandlesZeroInput) {
    EXPECT_EQ(add(0, 0), 0);
}

TEST(SourcePrng, OpenClose) {
    SourcePrng src;
    src.open();
    src.close();
}

TEST(SourcePrng, ReadBeforeOpen) {
    SourcePrng src;
    char buffer[1024];
    int ret = src.read(buffer, 1024);
    ASSERT_EQ(ret, -1);
}

TEST(SourcePrng, ReadAfterClose) {
    SourcePrng src;
    src.open();
    src.close();
    char buffer[1024];
    int ret = src.read(buffer, 1024);
    ASSERT_EQ(ret, -1);
}

TEST(SourcePrng, ReadNullBuffer) {
    SourcePrng src;
    src.open();
    int ret = src.read(nullptr, 4096);
    ASSERT_EQ(ret, -1);
    src.close();
}

TEST(SourcePrng, ReadZeroSize) {
    SourcePrng src;
    src.open();
    char buffer[1024];
    int ret = src.read(buffer, 0);
    ASSERT_EQ(ret, -1);
    src.close();
}

int writeBufferToFile(char *buffer, int size, const char* filename) {
    ofstream myfile;
    myfile.open(filename, ios::out | ios::trunc | ios::binary);
    myfile.write(buffer, size);
    myfile.close();
}

TEST(SourcePrng, Read4K) {
    SourcePrng src;
    src.open();
    char buffer[4096] = {0};
    int ret = src.read(buffer, 4096);
    ASSERT_EQ(ret, 4096);
    src.close();

    writeBufferToFile(buffer, 4096, "random.dat");

    auto cr = make_unique<CommandRunner>("ent -t random.dat");
    cr->run();
    
    auto strs = cr->getOutStrings(',');
    // TODO: remove debug code below.
    // for (const auto& str : strs) {
    //     cout << str << endl;
    // }

    EntValuesType entValues = toEntValues(strs, ENT_FIELD_OFFSET);
    ASSERT_EQ(entValues.fileBytes, 4096);
    ASSERT_GE(entValues.entropy, 7.93) << "Entropy is too low!";
    // TODO: the rest...
    // ASSERT_GE(entValues.chiSquare)
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
