#include "Product.hpp"

#include <iostream>

Product::Product() {
    this->name = "Default Product";
    this->price = 0.0;
}

Product::~Product() {
    std::cout << "Destructor called for product" << std::endl;
}
void Product::display() const {
    std::cout << "Product Name: " << name << std::endl;
    std::cout << "Product Price: " << price << std::endl;
}
void Product::setPrice(double price) {
    this->price = price;
}
double Product::getPrice() const {
    return this->price;
}