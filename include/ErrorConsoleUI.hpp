#pragma once

#include <string>

enum class ErrorLevel {
    INFO,
    WARNING,
    ERROR
};

class ErrorConsoleUI {
    public:
        static void displayError(const std::string& message, ErrorLevel level);
        static void displayInputError(const std::string& field);
        static void displayEmptyFieldError(const std::string& field);
        static void displayNegativeValueError(const std::string& field);
        static void displayNotFoundError(const std::string& item);
        static void displaySystemError(const std::string& message);
        static void displaySuccessMessage(const std::string& message);
};