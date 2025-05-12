#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <sstream>

namespace ANSI {
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string CYAN = "\033[36m";
    const std::string BLUE = "\033[34m";
    const std::string YELLOW = "\033[33m";
    const std::string MAGENTA = "\033[35m";
    const std::string WHITE = "\033[37m";

    const std::string MAGENTA_BOLD = "\033[45;1m";
    const std::string GREEN_BOLD = "\033[32;1m";
    const std::string RED_BOLD = "\033[31;1m";
    const std::string YELLOW_BOLD = "\033[33;1m";
    const std::string CYAN_BOLD = "\033[36;1m";
    const std::string BLUE_BOLD = "\033[34;1m";

    const std::string CLEAR_SCREEN = "\033[2J";
    const std::string RESET_CURSOR = "\033[H";

    const std::string WHITE_BRIGHT = "\033[32;1m";
    
    inline std::string colorize(const std::string& text, const std::string& code) {
        return code + text + RESET;
    }

    inline std::string notchedTemplate(const std::string& text, const std::string& code) {
        return CYAN + " [" + RESET + RED + "-" + RESET + CYAN + "] " + RESET + code + text  + RESET + CYAN + " [" + RESET + RED + "-" + RESET + CYAN + "] " + RESET;
    }

}