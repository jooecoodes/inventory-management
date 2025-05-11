#include "../include/Inventory.hpp"
#include "../include/InventoryApp.hpp"
#include "../include/ConsoleUI.hpp"
#include <iostream>

InventoryApp::InventoryApp() : inventory(), consoleUI() {

}

void InventoryApp::run() {
    int choice;
    bool sentinel = false;
    while(!sentinel) {
        consoleUI.displayMenuUI();
        std::cin >> choice;
        switch (choice) {
            case 1:
                consoleUI.displayAddProdUI();
                inventory.addProduct("Mango", "Fruits", 10, 9.2);
                std::cout << "TEST TEST" << std::endl;
                break;
            case 2:
                inventory.removeProduct("1");
                break;
            case 3:
                inventory.displayInventory();
                break;
            case 4:
                inventory.searchProduct("1");
                break;
            case 5:
                inventory.updateProduct("1", 15, 17.99);
                break;
            case 6:
                sentinel = true; 
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    }
}
