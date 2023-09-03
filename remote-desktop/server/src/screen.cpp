#include "screen.h"
#include <fstream>
#include <iostream>

void Screen::pollState()
{
    CGImageRef image = CGDisplayCreateImage(this->screenId);
    if (image == nullptr)
        return;

    size_t width = CGImageGetWidth(image);
    size_t height = CGImageGetHeight(image);
    CGDataProviderRef provider = CGImageGetDataProvider(image);
    CFDataRef data = CGDataProviderCopyData(provider);

    const uint8_t *pixelData = CFDataGetBytePtr(data);

    size_t dataSize = static_cast<size_t>(CFDataGetLength(data));

    this->pixels.assign(pixelData, pixelData + dataSize);
    this->height = height;
    this->width = width;

    CFRelease(data);
    CGImageRelease(image);
}

void Screen::writePixelsToFile(const std::string &filename) const
{
    std::ofstream outFile(filename, std::ios::binary);

    if (outFile.is_open())
    {
        outFile.write(reinterpret_cast<const char *>(pixels.data()), pixels.size());
        outFile.close();
    }
    else
    {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
    }
}

const std::vector<uint8_t> &Screen::getState()
{
    return this->pixels;
}
