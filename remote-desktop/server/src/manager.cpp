#include "manager.h"
#include <iostream>

bool Manager::screenAlreadyExists(CGDirectDisplayID displayId)
{
    for (uint32_t i = 0; i < this->screens.size(); ++i)
    {
        const Screen screen = this->screens[i];
        if (screen.screenId == displayId)
        {
            return true;
        }
    }
    return false;
};

void Manager::pollScreensFromOS()
{
    CGDirectDisplayID displays[16];
    uint32_t numDisplays;
    CGGetActiveDisplayList(16, displays, &numDisplays);

    for (uint32_t i = 0; i < numDisplays; ++i)
    {

        CGDirectDisplayID displayId = displays[i];

        if (!screenAlreadyExists(displayId))
        {
            this->screens.push_back(Screen(displayId));
        }
    }

    for (auto screen : this->screens)
    {
        screen.pollState();
        screen.writePixelsToFile(std::to_string(screen.screenId));
        const auto dimensions = screen.getDimensions();

        std::cout << dimensions.width << " " << dimensions.height << "\n";
    }
};