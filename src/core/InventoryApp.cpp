#include "../../include/core/Inventory.hpp"
#include "../../include/core/InventoryApp.hpp"
#include "../../include/ui/ConsoleUI.hpp"
#include "../../include/utils/InputHandler.hpp"
#include "../../include/utils/Utils.hpp"
#include "../../include/ui/ErrorConsoleUI.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

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
                    ErrorConsoleUI::displayEmptyFieldError("Menu choice");
                    goto Choice;
                }
                
                if (stringedInputChoice.length() > 1) {
                    ErrorConsoleUI::displayError("Please enter just one digit (1-6)", 
                                            ErrorLevel::WARNING);
                    goto Choice;
                }
                
                if (!isdigit(stringedInputChoice[0])) {
                    throw std::invalid_argument("Not a valid number");
                }
                
                choice = Utils::stringToInt(stringedInputChoice);
                if (choice < 1 || choice > 6) {
                    throw std::out_of_range("Menu option must be 1-6");
                }
                
            } catch (const std::invalid_argument& e) {
                ErrorConsoleUI::displayInputError("menu choice (must be integer)");
                goto Choice;
            } catch (const std::out_of_range& e) {
                ErrorConsoleUI::displayError("Invalid option (must be 1-6)", 
                                        ErrorLevel::ERROR);
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

                inventory.searchProducts(id);
                break;
            }
            case 5: {
                std::string id, name, category;
                int quantity;
                double price;

                consoleUI.displayUpdateProdUI();

                InputHandler::updateProdInputHandler(id, name, category, quantity, price);

                inventory.updateProduct(id, name, category, quantity, price);
                break;
            }
            case 6:
                consoleUI.displayExitUI();
                sentinel = true; 
                break;
        }
    }
}
