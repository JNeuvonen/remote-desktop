#pragma once
#include <vector>
#include "screen.h"

class Manager
{
public:
    Manager() {}
    void pollScreensFromOS();

private:
    std::vector<Screen> screens;
    bool screenAlreadyExists(CGDirectDisplayID displayId);
};