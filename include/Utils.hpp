#pragma once
#include <iostream>
#include <string>

class Utils {
    private:
        std::string test;
    public:
        Utils();
        ~Utils();
        void print() const;
        static std::string generateRandomInt(int length);
};