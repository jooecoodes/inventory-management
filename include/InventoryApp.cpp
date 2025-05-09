#include "../include/Inventory.hpp"
#include "../include/InventoryApp.hpp"
#include <iostream>

InventoryApp::InventoryApp() : inventory() {
    
}

void InventoryApp::run() {
    std::cout << "Welcome to the Inventory Management System!" << std::endl;
    
    inventory.addProduct("1", "Product A", "Category 1", 10, 19.99);

}
