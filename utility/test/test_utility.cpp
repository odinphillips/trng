#include <iostream>
#include <memory>

#include "gtest/gtest.h"

#include "utility.h"

using namespace std;

TEST(CommandRunner, DefaultConstruction) {
    auto cr = make_unique<CommandRunner>();
    string cmd = cr->getCommand();
    ASSERT_EQ(cmd, "");
}

TEST(CommandRunner, PassingCmdAtConstruction) {
    auto cr = make_unique<CommandRunner>("echo 123");
    string cmd = cr->getCommand();
    ASSERT_EQ(cmd, "echo 123");
}

TEST(CommandRunner, SetCommand) {
    auto cr = make_unique<CommandRunner>();
    string newCmd = "echo 123";
    cr->setCommand(newCmd);
    string cmd = cr->getCommand();
    ASSERT_EQ(cmd, newCmd);
    string anotherCmd = "ls -la";
    cr->setCommand(anotherCmd);
    cmd = cr->getCommand();
    ASSERT_EQ(cmd, anotherCmd);
}

TEST(CommandRunner, RunCommandEcho) {
    auto cr = make_unique<CommandRunner>("echo 123");
    cr->run();
    string outstr = cr->getOutString();
    ASSERT_EQ(outstr, string("123"));
}

TEST(CommandRunner, RunCommandEchoTwoWords) {
    auto cr = make_unique<CommandRunner>("echo Hello, World!");
    cr->run();
    string outstr = cr->getOutString();
    ASSERT_EQ(outstr, string("Hello, World!"));
}

TEST(CommandRunner, RunCommandGetTwoSubStrings) {
    auto cr = make_unique<CommandRunner>("echo Good Day");
    cr->run();
    string str = cr->getOutString(0);
    ASSERT_EQ(str, string("Good"));
    str = cr->getOutString(1);
    ASSERT_EQ(str, string("Day"));
}

TEST(CommandRunner, RunCommandGetThreeSubStrings) {
    auto cr = make_unique<CommandRunner>("echo Good Day Today");
    cr->run();
    string str = cr->getOutString(0);
    ASSERT_EQ(str, string("Good"));
    str = cr->getOutString(1);
    ASSERT_EQ(str, string("Day"));
    str = cr->getOutString(2);
    ASSERT_EQ(str, string("Today"));
}

TEST(CommandRunner, RunCommandGetThreeSubStringsCommaSep) {
    auto cr = make_unique<CommandRunner>("echo Good,Day,Today");
    cr->run();
    string str = cr->getOutString(0, ',');
    ASSERT_EQ(str, string("Good"));
    str = cr->getOutString(1, ',');
    ASSERT_EQ(str, string("Day"));
    str = cr->getOutString(2, ',');
    ASSERT_EQ(str, string("Today"));
}

// TODO: parse out a vector of strings
TEST(CommandRunner, RunCommandGetAllSubStringsCommaSep) {
    auto cr = make_unique<CommandRunner>("echo Good,Day,Today");
    cr->run();
    vector<string> strs = cr->getOutStrings(',');
    ASSERT_EQ(strs.size(), 3);
    ASSERT_EQ(strs[0], string("Good"));
    ASSERT_EQ(strs[1], string("Day"));
    ASSERT_EQ(strs[2], string("Today"));
}

// void add_testdata(void) {
//     system("mkdir -p testdata");
//     system("touch testdata/file1");
//     system("touch testdata/file2");
//     system("touch testdata/file3");
//     system("touch testdata/file4"); 
// }

// void remove_testdata(void) {
//     system("rm testdata/file1");
//     system("rm testdata/file2");
//     system("rm testdata/file3");
//     system("rm testdata/file4"); 
//     system("rmdir testdata");
// }

int main(int argc, char **argv) {
    // add_testdata();
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    // remove_testdata();
    return ret;
}
