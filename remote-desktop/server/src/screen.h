#pragma once
#include <ApplicationServices/ApplicationServices.h>
#include <vector>

class Screen
{
public:
    struct Dimensions
    {
        size_t width;
        size_t height;
    };
    const CGDirectDisplayID screenId;

    Screen(CGDirectDisplayID id)
        : screenId(id), pixels()
    {
    }

    void pollState();
    void writePixelsToFile(const std::string &filename) const;
    const std::vector<uint8_t> &getState();
    Dimensions getDimensions();

private:
    std::vector<uint8_t> pixels;
    Dimensions dimensions;
};
