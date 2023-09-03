#include <iostream>
#include <vector>
#include <ApplicationServices/ApplicationServices.h>
#include "screen.h"
#include "manager.h"

int main()
{

    Manager manager;
    manager.pollScreensFromOS();
    return 0;
}
