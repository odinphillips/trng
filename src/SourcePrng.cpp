#include <chrono>
#include <iostream>
#include <random>

#include "SourcePrng.h"

using namespace std;

int SourcePrng::open() {
    active = true;
    return 0;
}

int SourcePrng::close() {
    active = false;
    return 0;
}

int SourcePrng::read(void *buffer, size_t size) {
    if (!isActive()) {
        return -1;
    }

    if (!buffer) {
        return -1;
    }

    int seed = std::chrono::system_clock().now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0, 255);
    
    char* ptr = (char*)buffer;
    int rnd;
    // std::cout << "size = " << size << std::endl;
    for (size_t i = 0; i < size; i++) {
        rnd = distribution(generator);        
        ptr[i] = rnd & 255;
        // std::cout << (rnd & 255);
    }

    if (buffer && size) {
        return size;
    }
    return -1;
}
