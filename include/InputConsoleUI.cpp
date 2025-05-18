#include "InputConsoleUI.hpp"
#include "ANSI.hpp"
#include <iostream>

void InputConsoleUI::displayNamePrompt() {
    std::cout << ANSI::CYAN << "Name: " << ANSI::RESET;
}

void InputConsoleUI::displayCategoryPrompt() {
    std::cout << ANSI::CYAN << "Category: " << ANSI::RESET;
}

void InputConsoleUI::displayQuantityPrompt() {
    std::cout << ANSI::CYAN << "Quantity: " << ANSI::RESET;
}

void InputConsoleUI::displayPricePrompt() {
    std::cout << ANSI::CYAN << "Price: " << ANSI::RESET;
}

void InputConsoleUI::displayIDPrompt() {
    std::cout << ANSI::CYAN << "ID: " << ANSI::RESET;
}

void InputConsoleUI::displaySearchPrompt() {
    std::cout << ANSI::CYAN << "Search term: " << ANSI::RESET;
}

void InputConsoleUI::displayGenericPrompt(const std::string& fieldName) {
    std::cout << ANSI::CYAN << fieldName << ": " << ANSI::RESET;
}