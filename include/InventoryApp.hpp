#pragma once
#include "Inventory.hpp"

class InventoryApp {
    private:
        Inventory inventory;
    public:
        InventoryApp();
        void run();
};