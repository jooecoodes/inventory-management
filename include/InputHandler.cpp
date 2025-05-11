#include "InputHandler.hpp"
#include <iostream>

void InputHandler::addProdInputHandler(std::string& name, std::string category, int& quantity, double& price) {
    std::cout << "Name: ";
    std::cin >> name;

    std::cout << "Category: ";
    std::cin >> category;

    std::cout << "Quantity: ";
    std::cin >> quantity;

    std::cout << "Price: ";
    std::cin >> price;
}

void InputHandler::removeProdInputHandler(std::string& id) {
    std::cout << "ID: ";
    std::cin >> id;
}

void InputHandler::searchProdInputHandler(std::string& id) {
    std::cout << "ID (for search): ";
    std::cin >> id;
}

void InputHandler::updateProdInputHandler(std::string id, std::string& name, std::string& category, int& quantity, double& price) {
    std::cout << "New Name: ";
    std::cin >> name;

    std::cout << "New Category: ";
    std::cin >> category;

    std::cout << "New Quantity: ";
    std::cin >> quantity;

    std::cout << "New Price: ";
    std::cin >> price;
}