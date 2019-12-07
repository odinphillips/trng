/**
 * @file SourcePrng.h
 * @author Odin Phillips (odin.phillips.com)
 * @brief Pseudo random number source.
 * @version 0.1
 * @date 2019-09-28
 * 
 * @copyright Copyright (c) 2019 Odin Phillips
 * 
 */

#include "ISource.h"

// use c++ stl random for pseudo random data

class SourcePrng : public ISource {
public:
    SourcePrng(): active(false) {}
    ~SourcePrng() {}

    virtual int open() override;
    virtual int close() override;
    virtual int read(void *buffer, size_t size) override;

    bool isActive() const { return active; }

private:
    bool active;
};
