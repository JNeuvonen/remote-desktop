#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <SDL2/SDL.h>

void readPixelsFromFile(const std::string &filename, std::vector<uint8_t> &pixels)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open())
    {
        inFile.seekg(0, std::ios::end);
        size_t fileSize = inFile.tellg();
        inFile.seekg(0, std::ios::beg);

        pixels.resize(fileSize);
        inFile.read(reinterpret_cast<char *>(pixels.data()), fileSize);
        inFile.close();
    }
    else
    {
        std::cerr << "Could not open file for reading: " << filename << std::endl;
    }
}

int main()
{
    std::vector<uint8_t> pixels;
    readPixelsFromFile("1.testfile", pixels);

    for (auto pixel : pixels)
    {
        std::cout << static_cast<int>(pixel) << " ";
    }
    return 0;
}
