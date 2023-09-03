#pragma once
#include <ApplicationServices/ApplicationServices.h>
#include <vector>

class Screen
{
public:
    const CGDirectDisplayID screenId;

    Screen(CGDirectDisplayID id)
        : screenId(id), pixels()
    {
    }

    void pollState();
    void writePixelsToFile(const std::string &filename) const;
    const std::vector<uint8_t> &getState();

private:
    std::vector<uint8_t> pixels;
    size_t height;
    size_t width;
};
