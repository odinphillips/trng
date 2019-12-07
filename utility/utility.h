#pragma once

#include <cstring>
#include <string>
#include <vector>

// TODO: add utility namespace

struct EntValuesType {
    long fileBytes;
    double entropy;
    double chiSquare;
    double mean;
    double monteCarloPi;
    double serialCorrelation;
};

// Converts ENT list of strings to their numeric equivalents (EntValueType).
EntValuesType toEntValues(const std::vector<std::string>& entStrs, int offset = 0);

class CommandRunner {
public:
    CommandRunner() {
        memset(readBuffer, 0, 1024);
    }
    explicit CommandRunner(std::string cmd) : command(cmd) {
        memset(readBuffer, 0, 1024);
    }

    ~CommandRunner() {}

    int run(void);
    std::string getOutString(void);
    std::string getOutString(int index, char sep = ' ');
    std::vector<std::string> getOutStrings(char sep = ' ');

    std::string getCommand() const { return command; }
    void setCommand(std::string cmd) { command = cmd; }


private:
    char readBuffer[2048];
    std::string command;
    int pos;
};
