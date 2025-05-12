#include "../include/Inventory.hpp"
#include "../include/InventoryApp.hpp"
#include "../include/ConsoleUI.hpp"
#include "../include/InputHandler.hpp"
#include <iostream>

InventoryApp::InventoryApp() : inventory("../data/inventory.dat"), consoleUI() {

}

void InventoryApp::run() {
    int choice;
    bool sentinel = false;
    while(!sentinel) {
        consoleUI.displayMenuUI();
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::string name, category;
                int quantity;
                double price;

                consoleUI.displayAddProdUI();
                
                InputHandler::addProdInputHandler(name, category, quantity, price);
                
                inventory.addProduct(name, category, quantity, price);
                break;
            }
            case 2: {
                std::string id;

                consoleUI.displayRemoveProdUI();

                InputHandler::removeProdInputHandler(id);

                inventory.removeProduct(id);
                break;
            }
            case 3: {
                inventory.loadInventory();
                consoleUI.displayFields();

                inventory.displayInventory();
                break;
            }
            case 4: {
                std::string id;

                consoleUI.displaySearchProdUI();

                InputHandler::searchProdInputHandler(id);

                inventory.searchProduct(id);
                break;
            }
            case 5: {
                std::string id, name, category;
                int quantity;
                double price;

                consoleUI.displaySearchProdUI();

                InputHandler::updateProdInputHandler(id, name, category, quantity, price);

                inventory.updateProduct(id, name, category, quantity, price);
                break;
            }
            case 6:
                sentinel = true; 
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    }
}
