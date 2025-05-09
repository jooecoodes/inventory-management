#include "../include/Inventory.hpp"
#include "../include/InventoryApp.hpp"
#include "../include/ConsoleUI.hpp"
#include <iostream>

InventoryApp::InventoryApp() : inventory(), consoleUI() {
    
}

void InventoryApp::run() {
    consoleUI.displayMenuUI();
    
    inventory.addProduct("1", "Product A", "Category 1", 10, 19.99);
    inventory.addProduct("2", "Product B", "Category 2", 5, 29.99);
    inventory.addProduct("3", "Product C", "Category 3", 20, 9.99);

}
