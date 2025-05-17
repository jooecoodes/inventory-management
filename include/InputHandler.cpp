#include "InputHandler.hpp"
#include "Utils.hpp"
#include <iostream>
#include <string>

#include <limits>

void InputHandler::addProdInputHandler(std::string& name, std::string& category, int& quantity, double& price) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string stringedInputQuantity, stringedInputPrice;

    Name:
        std::cout << "Name: ";
        std::getline(std::cin,name);

        if (name.empty()) {
            std::cout << "Name cannot be empty. Please enter a valid name." << std::endl;
            goto Name;
        }

    Category:
        std::cout << "Category: ";
        std::getline(std::cin, category);
        if (category.empty()) {
            std::cout << "Category cannot be empty. Please enter a valid category." << std::endl;
            goto Category;
        }

    Quantity:
        try {
            std::cout << "Quantity: ";
            std::getline(std::cin, stringedInputQuantity);
        
            if (stringedInputQuantity.empty()) {
                std::cout << "Quantity cannot be empty. Please enter a valid quantity." << std::endl;
                goto Quantity;
            }
            quantity = Utils::stringToInt(stringedInputQuantity);
            if (quantity < 0) {
                std::cout << "Quantity cannot be negative. Please enter a valid quantity." << std::endl;
                goto Quantity;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for quantity. Please enter a valid integer." << std::endl;
            goto Quantity;
        } catch (const std::out_of_range& e) {
            std::cout << "Quantity is out of range. Please enter a valid integer." << std::endl;
            goto Quantity;
        }


    Price:
        try {
            std::cout << "Price: ";
            std::getline(std::cin, stringedInputPrice);
            if (stringedInputPrice.empty()) {
                std::cout << "Price cannot be empty. Please enter a valid price." << std::endl;
                goto Price;
            }
            price = Utils::stringToDouble(stringedInputPrice);
            if (price < 0) {
                std::cout << "Price cannot be negative. Please enter a valid price." << std::endl;
                goto Price;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for price. Please enter a valid number." << std::endl;
            goto Price;
        } catch (const std::out_of_range& e) {
            std::cout << "Price is out of range. Please enter a valid price." << std::endl;
            goto Price;
        }

    std::cout << "Product added successfully!" << std::endl;
}

void InputHandler::removeProdInputHandler(std::string& id) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    ID:
        std::cout << "ID: ";
        std::getline(std::cin, id);
        if (id.empty()) {
            std::cout << "ID cannot be empty. Please enter a valid ID." << std::endl;
            goto ID;
        }
        std::cout << "Product removed successfully!" << std::endl;
        std::cout << "Product with ID: " << id << " has been removed." << std::endl;
}

void InputHandler::searchProdInputHandler(std::string& id) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    ID:
        std::cout << "ID (for search): ";
        std::getline(std::cin, id);
        if (id.empty()) {
            std::cout << "ID cannot be empty. Please enter a valid ID." << std::endl;
            goto ID;
        }
        std::cout << "Product removed successfully!" << std::endl;
        std::cout << "Product with ID: " << id << " has been removed." << std::endl;

    
}

void InputHandler::updateProdInputHandler(std::string& id, std::string& name, std::string& category, int& quantity, double& price) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string stringedInputQuantity, stringedInputPrice;

    ID: 
        std::cout << "Enter the ID: ";
        std::getline(std::cin, id);
        
        if (id.empty()) {
            std::cout << "Name cannot be empty. Please enter a valid name." << std::endl;
            goto ID;
        }

    Name:
        std::cout << "New Name: ";
        std::getline(std::cin, name);
    
        if (name.empty()) {
            std::cout << "Name cannot be empty. Please enter a valid name." << std::endl;
            goto Name;
        }
    Category:
        std::cout << "New Category: ";
        std::cin >> category;

        if (category.empty()) {
            std::cout << "Category cannot be empty. Please enter a valid category." << std::endl;
            goto Category;
        }

    Quantity:
        try {
            std::cout << "New Quantity: ";
            std::getline(std::cin, stringedInputQuantity);

            if (stringedInputQuantity.empty()) {
                std::cout << "Quantity cannot be empty. Please enter a valid quantity." << std::endl;
                goto Quantity;
            }
            quantity = Utils::stringToInt(stringedInputQuantity);
            if (quantity < 0) {
                std::cout << "Quantity cannot be negative. Please enter a valid quantity." << std::endl;
                goto Quantity;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for quantity. Please enter a valid integer." << std::endl;
            goto Quantity;
        } catch (const std::out_of_range& e) {
            std::cout << "Quantity is out of range. Please enter a valid integer." << std::endl;
            goto Quantity;
        }

    Price:
        std::cout << "New Price: ";
        std::getline(std::cin, stringedInputPrice);
        try {
            if (stringedInputPrice.empty()) {
                std::cout << "Price cannot be empty. Please enter a valid price." << std::endl;
                goto Price;
            }
            price = Utils::stringToDouble(stringedInputPrice);
            if (price < 0) {
                std::cout << "Price cannot be negative. Please enter a valid price." << std::endl;
                goto Price;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for price. Please enter a valid number." << std::endl;
            goto Price;
        } catch (const std::out_of_range& e) {
            std::cout << "Price is out of range. Please enter a valid price." << std::endl;
            goto Price;
        }
}