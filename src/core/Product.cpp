#include "../../include/core/Product.hpp"
#include "../../include/ui/ConsoleUI.hpp"

#include <iostream>

Product::Product() {
    this->name = "Default Product";
    this->price = 0.0;
}

Product::Product(const std::string& id, const std::string& name, const std::string& category, int quantity, double price)
    : id(id), name(name), category(category), quantity(quantity), price(price) {
}

void Product::display() const {
    ConsoleUI::displayProduct(this->id, this->name, this->category, this->quantity, this->price);
}

std::string Product::getID() const {
    return this->id;
}

std::string Product::getName() const {
    return this->name;
}

std::string Product::getCategory() const {
    return this->category;
}

int Product::getQuantity() const {
    return this->quantity;
}

double Product::getPrice() const {
    return this->price;
}

void Product::setID(const std::string& id) {
    this->id = id;
}

void Product::setName(const std::string& name) {
    this->name = name;
} 

void Product::setCategory(const std::string& category) {
    this->category = category;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Product::setPrice(double price) {
    this->price = price;
}