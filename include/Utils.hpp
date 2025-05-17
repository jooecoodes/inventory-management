#pragma once
#include <iostream>
#include <string>
#include <vector>

class Utils {
    private:
        std::string test;
    public:
        Utils();
        ~Utils();
        void print() const;
        static std::string generateRandomInt(int length);
        static std::vector<std::string> splitStringByComma(const std::string& input);
        static double stringToDouble(const std::string str);
        static int stringToInt(const std::string str);
        static std::string intToString(int num);
        static std::string doubleToString(double num);
};