#pragma once

#include <string>

class InputConsoleUI {
    public:
        static void displayNamePrompt();
        static void displayCategoryPrompt();
        static void displayQuantityPrompt();
        static void displayPricePrompt();
        static void displayIDPrompt();
        static void displaySearchPrompt();

        static void displayGenericPrompt(const std::string& fieldName);
};