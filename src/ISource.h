/**
 * @file ISource.h
 * @author Odin Phillips (odin.phillips@gmail.com)
 * @brief libtrng Source interface. 
 * @version 0.1
 * @date 2019-09-28
 * 
 * @copyright Copyright (c) 2019 Odin Phillips
 * 
 */

#include <cstdlib>

class ISource {
public:
    virtual int open() = 0;
    virtual int close() = 0;
    virtual int read(void *buffer, size_t size) = 0;
};
