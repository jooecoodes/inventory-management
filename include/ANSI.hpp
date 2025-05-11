#pragma once

#include <string>
#include <iostream>

namespace ANSI {
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string CYAN = "\033[36m";
    
    inline std::string colored(const std::string& text, const std::string& code) {
        return code + text + RESET;
    }

    inline std::string notchedTemplate(const std::string& text, const std::string& code) {
        return CYAN + " [" + RESET + RED + "-" + RESET + CYAN + "] " + RESET + code + text  + RESET + CYAN + " [" + RESET + RED + "-" + RESET + CYAN + "] " + RESET;
    }
}