#include "ConsoleUI.hpp"
#include "ANSI.h"

void ConsoleUI::displayMenuUI() const {
    std::cout << ANSI::colored("Welcome to the Inventory Management System!", ANSI::CYAN) << std::endl;
    std::cout << ANSI::colored("1. Add Product", ANSI::GREEN) << std::endl;
    std::cout << ANSI::colored("2. Remove Product", ANSI::GREEN) << std::endl;
    std::cout << ANSI::colored("3. Display Inventory", ANSI::GREEN) << std::endl;
    std::cout << ANSI::colored("4. Search Product", ANSI::GREEN) << std::endl;
    std::cout << ANSI::colored("5. Update Product", ANSI::GREEN) << std::endl;
    std::cout << ANSI::colored("6. Exit", ANSI::RED) << std::endl;
}
