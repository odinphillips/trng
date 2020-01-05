/**
 * @file SourceAudio.h
 * @author Odin Phillips (odin.phillips.com)
 * @brief Audio random number source.
 * @version 0.1
 * @date 2019-12-07
 * 
 * @copyright Copyright (c) 2019 Odin Phillips
 * 
 */

#include "ISource.h"

// Uses third-party library PortAudio as a source to generate random numbers.

class SourceAudio : public ISource {
public:
    SourceAudio(): active(false) {}
    ~SourceAudio() {}

    virtual int open() override;
    virtual int close() override;
    virtual int read(void *buffer, size_t size) override;

    bool isActive() const { return active; }

private:
    bool active;
};
