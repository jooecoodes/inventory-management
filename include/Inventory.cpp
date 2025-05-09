#include "Inventory.hpp"
#include "FileManager.hpp"

#include <iostream>
#include <string>

Inventory::Inventory() {
    inventoryFileName = "../data/inventory.dat";
}

void Inventory::addProduct(const std::string& id, const std::string& name, const std::string& category, int quantity, double price) {
    Product product;
    product.setID(id);
    product.setName(name);
    product.setCategory(category);
    product.setQuantity(quantity);
    product.setPrice(price);

    products[id] = product;
    FileManager::writeToInventory(inventoryFileName, id + "," + name + "," + category + "," + std::to_string(quantity) + "," + std::to_string(price));
}

void Inventory::removeProduct(const std::string& id) {
    products.erase(id);
    FileManager::deleteFromInventory(inventoryFileName, id);
}

void Inventory::displayInventory() const {
    for (const auto& pair : products) {
        pair.second.display();
    }
}

void Inventory::searchProduct(const std::string& id) const {
    for(const auto& pair : products) {
        if(pair.first == id) {
            pair.second.display();
            return;
        }
    }
}

void Inventory::updateProduct(const std::string& id, int quantity, double price) {
    for(auto& pair : products) {
        if(pair.first == id) {
            pair.second.setQuantity(quantity);
            pair.second.setPrice(price);

            FileManager::updateInventory(inventoryFileName, id, id + "," + pair.second.getName() + "," + pair.second.getCategory() + "," + std::to_string(quantity) + "," + std::to_string(price));
        }
    }
}