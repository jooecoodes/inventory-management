#pragma once
#include "Inventory.hpp"
#include "ConsoleUI.hpp"

class InventoryApp {
    private:
        Inventory inventory;
        ConsoleUI consoleUI;
    public:
        InventoryApp();
        void run();
};