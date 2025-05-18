#include "ErrorConsoleUI.hpp"
#include "ANSI.hpp"

#define ERROR_SYMBOL   "✖"
#define WARNING_SYMBOL "⚠"
#define SUCCESS_SYMBOL "✓"

void ErrorConsoleUI::displayError(const std::string& message, ErrorLevel level) {
    std::string color;
    switch(level) {
        case ErrorLevel::WARNING:
            color = ANSI::YELLOW_BOLD;
            break;
        case ErrorLevel::ERROR:
            color = ANSI::RED_BOLD;
            break;
        case ErrorLevel::INFO:
            color = ANSI::CYAN_BOLD;
            break;
        default:
            color = ANSI::WHITE_BOLD;
    }
    
    std::cout << color << " ⚠  " << message << ANSI::RESET << "\n";
}

void ErrorConsoleUI::displayInputError(const std::string& field) {
    displayError("Invalid input for " + field + ". Please try again.", ErrorLevel::WARNING);
}

void ErrorConsoleUI::displayEmptyFieldError(const std::string& field) {
    displayError(field + " cannot be empty. Please enter a value.", ErrorLevel::WARNING);
}

void ErrorConsoleUI::displayNegativeValueError(const std::string& field) {
    displayError(field + " cannot be negative. Please enter a positive value.", ErrorLevel::WARNING);
}

void ErrorConsoleUI::displayNotFoundError(const std::string& item) {
    displayError(item + " not found in inventory.", ErrorLevel::ERROR);
}

void ErrorConsoleUI::displaySystemError(const std::string& message) {
    displayError("SYSTEM ERROR: " + message, ErrorLevel::ERROR);
}

void ErrorConsoleUI::displaySuccessMessage(const std::string& message) {
    displayError("✓ " + message, ErrorLevel::INFO); 
}