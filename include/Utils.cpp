#include "Utils.hpp"
#include <random>
#include <string>
#include <sstream>
#include <vector>

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

std::vector<std::string> Utils::splitStringByComma(const std::string& input) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(input);
    
    while (std::getline(tokenStream, token, ',')) {
        tokens.push_back(token);
    }
    
    return tokens;
}

double Utils::stringToDouble(const std::string str) {
    size_t pos;
    double result = std::stod(str, &pos);

    return result;
}
int Utils::stringToInt(const std::string str) {
    size_t pos;
    int result = std::stoi(str, &pos);

    return result;
}
std::string Utils::intToString(int value) {
    return std::to_string(value);
}
std::string Utils::doubleToString(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}