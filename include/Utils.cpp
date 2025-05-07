#include "Utils.hpp"

Utils::Utils() {
    this->test = "test";
}
Utils::~Utils() {
    std::cout << "Destructor called" << std::endl;
}
void Utils::print() const {
    std::cout << test << std::endl;
}
