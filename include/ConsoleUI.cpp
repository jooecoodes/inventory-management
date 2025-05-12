#include "ConsoleUI.hpp"
#include "ANSI.hpp"
#include <thread>
#include <chrono>

namespace {
    const int ID_WIDTH = 12;
    const int NAME_WIDTH = 20;
    const int CAT_WIDTH = 15;
    const int QTY_WIDTH = 8;
    const int PRICE_WIDTH = 10;

    struct TableFormat {
        static std::string divider() {
            return  "+" + std::string(ID_WIDTH+2, '-') 
                    + "+" + std::string(NAME_WIDTH+2, '-') 
                    + "+" + std::string(CAT_WIDTH+2, '-') 
                    + "+" + std::string(QTY_WIDTH+2, '-') 
                    + "+" + std::string(PRICE_WIDTH+2, '-') + "+";
        }
    };

    void slowPrint(const std::string& text, int delay_ms = 10) {
        for (char c : text) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        }
    }

    void separatorLine(char symbol = '=', int length = 40) {
        std::cout << ANSI::CYAN << std::string(length, symbol) << ANSI::RESET << "\n";
    }

}

void ConsoleUI::displayMenuUI() const {
    std::cout << ANSI::CLEAR_SCREEN << ANSI::RESET_CURSOR;
    separatorLine();
    slowPrint(ANSI::CYAN_BOLD + "  Inventory Management System  " + ANSI::RESET + "\n", 2);
    separatorLine();

    std::cout << ANSI::colorize(" [1] ➤ Add Product\n", ANSI::GREEN_BOLD);
    std::cout << ANSI::colorize(" [2] ➤ Remove Product\n", ANSI::RED_BOLD);
    std::cout << ANSI::colorize(" [3] ➤ View Inventory\n", ANSI::BLUE_BOLD);
    std::cout << ANSI::colorize(" [4] ➤ Search Product\n", ANSI::YELLOW_BOLD);
    std::cout << ANSI::colorize(" [5] ➤ Update Product\n", ANSI::MAGENTA_BOLD);
    std::cout << ANSI::colorize(" [6] ➤ Exit\n", ANSI::WHITE_BRIGHT);

    separatorLine();
    std::cout << ANSI::colorize(" Enter your choice: ", ANSI::CYAN_BOLD);
}

void ConsoleUI::displayAddProdUI() {
    std::cout << ANSI::notchedTemplate("Add New Product", ANSI::GREEN_BOLD) << "\n";
    slowPrint("Please enter the details of the new product...\n", 15);
}

void ConsoleUI::displayRemoveProdUI() const {
    std::cout << ANSI::notchedTemplate("Remove Product", ANSI::RED_BOLD) << "\n";
    slowPrint("Enter the product ID or name to remove...\n", 15);
}

void ConsoleUI::displayInventoryUI() const {
    std::cout << ANSI::notchedTemplate("Inventory List", ANSI::BLUE_BOLD) << "\n";
    slowPrint("Loading inventory...\n", 15);

}

void ConsoleUI::displaySearchProdUI() const {
    std::cout << ANSI::notchedTemplate("Search Product", ANSI::YELLOW_BOLD) << "\n";
    slowPrint("Enter the product keyword to search...\n", 15);
}

void ConsoleUI::displayUpdateProdUI() const {
    std::cout << ANSI::notchedTemplate("Update Product", ANSI::MAGENTA_BOLD) << "\n";
    slowPrint("Enter the product ID and new information...\n", 15);
}

void ConsoleUI::displayExitUI() const {
    std::cout << "\n";
    slowPrint(ANSI::RED_BOLD + "Exiting the system...\n" + ANSI::RESET, 25);
    slowPrint(ANSI::CYAN + "Thank you for using the Inventory Manager.\n" + ANSI::RESET, 25);
}

void ConsoleUI::displayFields() {

    std::cout << ANSI::CYAN << TableFormat::divider() << ANSI::RESET << "\n"
            << ANSI::CYAN << "| " << std::setw(ID_WIDTH) << std::left << "Product ID" << " | "
            << std::setw(NAME_WIDTH) << std::left << "Name" << " | "
            << std::setw(CAT_WIDTH) << std::left << "Category" << " | "
            << std::setw(QTY_WIDTH) << std::left << "Quantity" << " | "
            << std::setw(PRICE_WIDTH) << std::left << "Price" << " |" << ANSI::RESET << "\n"
            << ANSI::CYAN << TableFormat::divider() << ANSI::RESET << "\n";
}


void ConsoleUI::displayProduct(const std::string& id, const std::string& name, const std::string& category, int quantity, double price) {

    std::cout << "| " << std::setw(ID_WIDTH) << std::left << id << " | "
            << std::setw(NAME_WIDTH) << std::left << name << " | "
            << std::setw(CAT_WIDTH) << std::left << category << " | "
            << std::setw(QTY_WIDTH) << std::left << quantity << " | "
            << std::setw(PRICE_WIDTH) << std::left << ("$" + std::to_string(price)) << " |\n"
            << ANSI::CYAN << TableFormat::divider() << ANSI::RESET << "\n";
}

