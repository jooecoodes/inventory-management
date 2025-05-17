#include <iostream>
#include <windows.h>

#include "../include/InventoryApp.hpp"


int main() {
    SetConsoleOutputCP(CP_UTF8);

    try {
        InventoryApp app;
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}