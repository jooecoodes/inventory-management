#include "InputHandler.hpp"
#include "Utils.hpp"
#include "ErrorConsoleUI.hpp"
#include "InputConsoleUI.hpp"
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

void InputHandler::searchProdInputHandler(std::string& name) {
    InputConsoleUI::displaySearchPrompt();
    Name:
        std::getline(std::cin, name);
        if (name.empty()) {
            ErrorConsoleUI::displayEmptyFieldError("Search term");
            goto Name;
        }
}

void InputHandler::updateProdInputHandler(std::string& id, std::string& name, std::string& category, int& quantity, double& price) {
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

    ErrorConsoleUI::displaySuccessMessage("Product updated successfully!");
}