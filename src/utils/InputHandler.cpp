#include "../../include/utils/InputHandler.hpp"
#include "../../include/utils/Utils.hpp"
#include "../../include/ui/ErrorConsoleUI.hpp"
#include "../../include/ui/InputConsoleUI.hpp"
#include "../../include/core/Inventory.hpp"
#include <iostream>
#include <string>
#include <limits>

void InputHandler::addProdInputHandler(std::string& name, std::string& category, int& quantity, double& price) {
    std::string stringedInputQuantity, stringedInputPrice;

    Name:
        InputConsoleUI::displayNamePrompt();
        std::getline(std::cin, name);
        if (name.empty()) {
            ErrorConsoleUI::displayEmptyFieldError("Name");
            goto Name;
        }

    Category:
        InputConsoleUI::displayCategoryPrompt();
        std::getline(std::cin, category);
        if (category.empty()) {
            ErrorConsoleUI::displayEmptyFieldError("Category");
            goto Category;
        }

    Quantity:
        try {
            InputConsoleUI::displayQuantityPrompt();
            std::getline(std::cin, stringedInputQuantity);
        
            if (stringedInputQuantity.empty()) {
                ErrorConsoleUI::displayEmptyFieldError("Quantity");
                goto Quantity;
            }
            quantity = Utils::stringToInt(stringedInputQuantity);
            if (quantity < 0) {
                ErrorConsoleUI::displayNegativeValueError("Quantity");
                goto Quantity;
            }
        } catch (const std::invalid_argument& e) {
            ErrorConsoleUI::displayInputError("quantity (must be integer)");
            goto Quantity;
        } catch (const std::out_of_range& e) {
            ErrorConsoleUI::displayError("Quantity value is too large", ErrorLevel::ERROR);
            goto Quantity;
        }

    Price:
        try {
            InputConsoleUI::displayPricePrompt();
            std::getline(std::cin, stringedInputPrice);
            if (stringedInputPrice.empty()) {
                ErrorConsoleUI::displayEmptyFieldError("Price");
                goto Price;
            }
            price = Utils::stringToDouble(stringedInputPrice);
            if (price < 0) {
                ErrorConsoleUI::displayNegativeValueError("Price");
                goto Price;
            }
        } catch (const std::invalid_argument& e) {
            ErrorConsoleUI::displayInputError("price (must be number)");
            goto Price;
        } catch (const std::out_of_range& e) {
            ErrorConsoleUI::displayError("Price value is too large", ErrorLevel::ERROR);
            goto Price;
        }

    ErrorConsoleUI::displaySuccessMessage("Product added successfully!");
}

void InputHandler::removeProdInputHandler(std::string& id) {
    ID:
        InputConsoleUI::displayIDPrompt();
        std::getline(std::cin, id);
        if (id.empty()) {
            ErrorConsoleUI::displayEmptyFieldError("ID");
            goto ID;
        }
    ErrorConsoleUI::displaySuccessMessage("Product removed successfully!");
    std::cout << "Product with ID: " << id << " has been removed." << std::endl;
}

void InputHandler::searchProdInputHandler(Inventory& inventory) {
    InputConsoleUI::displayGenericPrompt("Choose 1 if you wish to search by ID, 2 if you wish to switch by name");
    std::string choice;
    std::getline(std::cin, choice);

    if (choice == "1") {
        std::string id;

        ID:
            try {
                InputConsoleUI::displaySearchPromptID();
                std::getline(std::cin, id);
                if (id.empty()) {
                    ErrorConsoleUI::displayEmptyFieldError("ID");
                    goto ID;
                }
            } catch (const std::invalid_argument& e) {
                ErrorConsoleUI::displayInputError("Input (must be integer)");
                goto ID;
            } catch (const std::out_of_range& e) {
                ErrorConsoleUI::displayError("Value is too large", ErrorLevel::ERROR);
                goto ID;
            }
        
        inventory.searchProductByID(id);
        return;
    }
    if (choice != "2") {
        ErrorConsoleUI::displayError("Invalid choice. Please enter 1 or 2.", ErrorLevel::ERROR);
        return;
    }

    std::string name;

    InputConsoleUI::displaySearchPromptName();
    Name:
        std::getline(std::cin, name);
        if (name.empty()) {
            ErrorConsoleUI::displayEmptyFieldError("Search by name");
            goto Name;
        }
    
        inventory.searchProductByName(name);
}

void InputHandler::updateProdInputHandler(std::string& id, std::string& name, std::string& category, int& quantity, double& price, Inventory& inventory) {
    InputConsoleUI::displayGenericPrompt("Choose 1 if you wish to stock in/stock out, 2 if you wish to update the product");
    std::string choice;
    std::getline(std::cin, choice);

    if (choice == "1") {
        std::string stringedInputQuantity;
        int quantityChange;

        QuantityChange:
            try {
                InputConsoleUI::displayGenericPrompt("Enter the ID");
                std::getline(std::cin, id);
                if (id.empty()) {
                    ErrorConsoleUI::displayEmptyFieldError("ID");
                    goto QuantityChange;
                }
                InputConsoleUI::displayGenericPrompt("Enter the quantity change (positive for stock in, negative for stock out)");
                std::getline(std::cin, stringedInputQuantity);
                if (stringedInputQuantity.empty()) {
                    ErrorConsoleUI::displayEmptyFieldError("Quantity");
                    goto QuantityChange;
                }
                quantityChange = Utils::stringToInt(stringedInputQuantity);
            } catch (const std::invalid_argument& e) {
                ErrorConsoleUI::displayInputError("quantity change (must be integer)");
                goto QuantityChange;
            } catch (const std::out_of_range& e) {
                ErrorConsoleUI::displayError("Quantity value is too large", ErrorLevel::ERROR);
                goto QuantityChange;
            }

        // Call the function to update stock
        inventory.updateStock(id, quantityChange);
        return;
    }
    if (choice != "2") {
        ErrorConsoleUI::displayError("Invalid choice. Please enter 1 or 2.", ErrorLevel::ERROR);
        return;
    }

    std::string stringedInputQuantity, stringedInputPrice;

    ID: 
        InputConsoleUI::displayGenericPrompt("Enter the ID");
        std::getline(std::cin, id);
        if (id.empty()) {
            ErrorConsoleUI::displayEmptyFieldError("ID");
            goto ID;
        }

    Name:
        InputConsoleUI::displayGenericPrompt("New Name");
        std::getline(std::cin, name);
        if (name.empty()) {
            ErrorConsoleUI::displayEmptyFieldError("Name");
            goto Name;
        }

    Category:
        InputConsoleUI::displayGenericPrompt("New Category");
        std::getline(std::cin, category);
        if (category.empty()) {
            ErrorConsoleUI::displayEmptyFieldError("Category");
            goto Category;
        }

    Quantity:
        try {
            InputConsoleUI::displayGenericPrompt("New Quantity");
            std::getline(std::cin, stringedInputQuantity);
            if (stringedInputQuantity.empty()) {
                ErrorConsoleUI::displayEmptyFieldError("Quantity");
                goto Quantity;
            }
            quantity = Utils::stringToInt(stringedInputQuantity);
            if (quantity < 0) {
                ErrorConsoleUI::displayNegativeValueError("Quantity");
                goto Quantity;
            }
        } catch (const std::invalid_argument& e) {
            ErrorConsoleUI::displayInputError("quantity (must be integer)");
            goto Quantity;
        } catch (const std::out_of_range& e) {
            ErrorConsoleUI::displayError("Quantity value is too large", ErrorLevel::ERROR);
            goto Quantity;
        }

    Price:
        try {
            InputConsoleUI::displayGenericPrompt("New Price");
            std::getline(std::cin, stringedInputPrice);
            if (stringedInputPrice.empty()) {
                ErrorConsoleUI::displayEmptyFieldError("Price");
                goto Price;
            }
            price = Utils::stringToDouble(stringedInputPrice);
            if (price < 0) {
                ErrorConsoleUI::displayNegativeValueError("Price");
                goto Price;
            }
        } catch (const std::invalid_argument& e) {
            ErrorConsoleUI::displayInputError("price (must be number)");
            goto Price;
        } catch (const std::out_of_range& e) {
            ErrorConsoleUI::displayError("Price value is too large", ErrorLevel::ERROR);
            goto Price;
        }
    
    inventory.updateProduct(id, name, category, quantity, price);
}