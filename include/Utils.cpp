#include "Utils.hpp"
#include <random>


Utils::Utils() {
    this->test = "test";
}
Utils::~Utils() {
    std::cout << "Destructor called" << std::endl;
}
void Utils::print() const {
    std::cout << test << std::endl;
}

std::string Utils::generateRandomInt(int length) {
    const std::string charset =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
    
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, charset.size() - 1);
    
    std::string result;
    result.reserve(length);
    
    for (int i = 0; i < length; ++i) {
        result += charset[distribution(generator)];
    }
    
    return result;
}
