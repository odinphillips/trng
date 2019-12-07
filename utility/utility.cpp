#include <iostream>

#include "utility.h"

using namespace std;

// Converts ENT list of strings to their numeric equivalents (EntValueType).
//
// Assumes that 'entStrs' is a list numeric strings in this order:
// { "<File-Bytes>", "<Entropy>", "<Chi-Square>", "<Mean>",  "<Monte-Carlo-Pi>", "<Serial-Correlation>" }
//
// Note: this function was original created for using with CommandRunner::getOutStrings(),
EntValuesType toEntValues(const std::vector<std::string>& entStrs, int offset) {
    EntValuesType entValues;
    // cout << "entStrs[" << 0 << " + 1]" << entStrs[0 + 1].c_str() << std::endl;
    entValues.fileBytes = atol(entStrs[offset + 0].c_str());
    entValues.entropy = atof(entStrs[offset + 1].c_str());
    entValues.chiSquare = atof(entStrs[offset + 2].c_str());
    entValues.mean = atof(entStrs[offset + 3].c_str());
    entValues.monteCarloPi = atof(entStrs[offset + 4].c_str());
    entValues.serialCorrelation = atof(entStrs[offset + 5].c_str());
    return entValues;
}

int CommandRunner::run(void) {
    FILE *fptr = popen(command.c_str(), "r");
    if (fptr) {
        size_t bytesRead = fread(readBuffer, 1, 1024, fptr);
        pclose(fptr);
    }
    
    return 0;
}

void removeNewlineChars(char* str, char replaceWith = '\0') {
    int pos = 0;
    while (str[pos]) {
        if (str[pos] == '\n' || str[pos] == '\r') {
            str[pos] = replaceWith;
        }
        pos++;
    }   
}

void removeNewlineChars(string& str) {
    for (int pos = 0; pos < str.size(); pos++) {
        if (str[pos] == '\n' || str[pos] == '\r') {
            str.erase(pos); // erase until end of string
        }
    }   
}

std::string CommandRunner::getOutString(void) {
    removeNewlineChars(readBuffer);
    return string(readBuffer);
}

std::string CommandRunner::getOutString(int index, char sep) {
    string subString;
    int pos = 0;
    int i = 0;
    while(readBuffer[pos]) {
        if (readBuffer[pos] == sep) {
            if (i == index) {
                break;
            }
            i++;
        }
        else if (i == index) {
            subString += readBuffer[pos];
        }
        pos++;
    }
    removeNewlineChars(subString);
    return subString;
}

vector<string> CommandRunner::getOutStrings(char sep) {
    vector<string> strs;

    string subString;
    int pos = 0;
    int i = 0;
    while(readBuffer[pos]) {
        if (readBuffer[pos] == sep) {
            strs.push_back(subString);
            subString = "";
        } else {
            subString += readBuffer[pos];
        }
        pos++;
    }
    removeNewlineChars(subString);
    strs.push_back(subString);
    return strs;
}
