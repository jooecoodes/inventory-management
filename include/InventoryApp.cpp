#include "../include/Inventory.hpp"
#include "../include/InventoryApp.hpp"
#include "../include/ConsoleUI.hpp"
#include "../include/InputHandler.hpp"
#include "../include/Utils.hpp"
#include <iostream>

InventoryApp::InventoryApp() : inventory("../data/inventory.dat"), consoleUI() {

}

void InventoryApp::run() {
    int choice;
    std::string stringedInputChoice;

    bool sentinel = false;

    while(!sentinel) {
        consoleUI.displayMenuUI();

        Choice:
            try {

                std::getline(std::cin, stringedInputChoice);
                if (stringedInputChoice.empty()) {
                    std::cout << "Input cannot be empty. Please enter a valid choice." << std::endl;
                    goto Choice;
                }
                if (stringedInputChoice.length() > 1) {
                    std::cout << "Input is too long. Please enter a single digit." << std::endl;
                    goto Choice;
                }
            
                choice = Utils::stringToInt(stringedInputChoice);   
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input. Please enter a number." << std::endl;
                goto Choice;
            } catch (const std::out_of_range& e) {
                std::cout << "Input is out of range. Please enter a valid number." << std::endl;
                goto Choice;
            }
        

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
                consoleUI.displayFields();

                inventory.displayInventory();
                break;
            }
            case 4: {
                std::string id;

                consoleUI.displaySearchProdUI();

                InputHandler::searchProdInputHandler(id);
                std::cout << "Search product before" << std::endl;

                inventory.searchProducts(id);
                std::cout << "Search product after" << std::endl;
                break;
            }
            case 5: {
                std::string id, name, category;
                int quantity;
                double price;

                consoleUI.displaySearchProdUI();

                InputHandler::updateProdInputHandler(id, name, category, quantity, price);

                inventory.updateProduct(id, name, category, quantity, price);
                std::cout << "After inventory update product" << std::endl;
                break;
            }
            case 6:
                sentinel = true; 
                break;
        }
    }
}
