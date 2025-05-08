#include "../include/Inventory.hpp"
#include "../include/InventoryApp.hpp"
#include <iostream>

InventoryApp::InventoryApp() : inventory() {
    // Constructor implementation
}

void InventoryApp::run() {
    // Main application logic
    std::cout << "Welcome to the Inventory Management System!" << std::endl;
    // Additional code for running the application
    
    inventory.addProduct("1", "Product A", "Category 1", 10, 19.99);

}
