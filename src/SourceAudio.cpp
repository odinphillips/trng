#include <chrono>
#include <iostream>
#include <random>

#include "SourceAudio.h"

using namespace std;

int SourceAudio::open() {
    active = true;
    return 0;
}

int SourceAudio::close() {
    active = false;
    return 0;
}

int SourceAudio::read(void *buffer, size_t size) {
    if (!isActive()) {
        return -1;
    }

    if (!buffer) {
        return -1;
    }

    return 0;
}
