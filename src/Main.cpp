#include <iostream>
#include <windows.h>

#include "../include/InventoryApp.hpp"


int main() {
    SetConsoleOutputCP(CP_UTF8);

    if (!SetConsoleOutputCP(CP_UTF8)) {
        std::cerr << "Failed to set console output to UTF-8. Error: " << GetLastError() << std::endl;
        return 1;
    }
    
    try {
        InventoryApp app;
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}