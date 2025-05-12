#include <iostream>
#include <windows.h>

#include "../include/InventoryApp.hpp"


int main() {
    SetConsoleOutputCP(CP_UTF8);

    InventoryApp app;
    app.run();

    return 0;
}