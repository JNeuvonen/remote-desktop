#include <ApplicationServices/ApplicationServices.h>

#include <iostream>
#include <vector>

#include "manager.h"

int main() {
    Manager manager;

    manager.pollScreensFromOS();

    return 0;
}
