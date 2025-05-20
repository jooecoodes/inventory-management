#include "../../include/core/Inventory.hpp"
#include "../../include/utils/FileManager.hpp"
#include "../../include/utils/Utils.hpp"
#include "../../include/core/Product.hpp"
#include "../../include/ui/ErrorConsoleUI.hpp"

#include <iostream>
#include <string>
#include <vector>

Inventory::Inventory(std::string filePath) {
    inventoryFileName = filePath;
}

void Inventory::addProduct(const std::string& name, const std::string& category, int quantity, double price) {
    std::string randomID = Utils::generateRandomInt(5);

    Product product;
    product.setID(randomID);
    product.setName(name);
    product.setCategory(category);
    product.setQuantity(quantity);
    product.setPrice(price);

    this->products[randomID] = product;
    FileManager::writeToInventory(inventoryFileName, randomID + "," + name + "," + category + "," + std::to_string(quantity) + "," + std::to_string(price));
}

void Inventory::removeProduct(const std::string& id) {
    this->products.erase(id);
    FileManager::deleteFromInventory(inventoryFileName, id);
}

void Inventory::displayInventory() {
    loadInventory();
    for (const auto& pair : products) {
        pair.second.display();
    }

    std::cout << "Total Inventory Value: " << inventoryValue() << std::endl;
}

void Inventory::searchProductByName(const std::string& name) {

    std::vector<std::string> productLines = FileManager::readToInventory(inventoryFileName);
    std::map<std::string, Product> searchedProducts;

    for(const auto& product : productLines) {
        std::vector<std::string> fields = Utils::splitStringByComma(product);

        if(fields[1].find(name) != std::string::npos) {
            searchedProducts.emplace(
                fields[0],  
                Product {
                    fields[0],       
                    fields[1],       
                    fields[2],       
                    Utils::stringToInt(fields[3]),  
                    Utils::stringToDouble(fields[4]) 
                }
            );
        }
    }

    for (const auto& searchedPair : searchedProducts) {
        searchedPair.second.display();
        return;
    }

    ErrorConsoleUI::displayError("Product not found with the name: " + name, ErrorLevel::ERROR);

}

void Inventory::searchProductByID(const std::string& id) {
    loadInventory();

    for(const auto& pair : products) {
        if(pair.first == id) {
            pair.second.display();
            return;
        }
    }

    ErrorConsoleUI::displayError("Product not found with ID: " + id, ErrorLevel::ERROR);

}

void Inventory::updateProduct(const std::string& id, const std::string& name,const std::string& category, int quantity, double price) {
    loadInventory();

    for(auto& pair : products) {
        if(pair.first == id) {
            pair.second.setName(name);
            pair.second.setCategory(category);
            pair.second.setQuantity(quantity);
            pair.second.setPrice(price);

            FileManager::updateInventory(inventoryFileName, id, id + "," + pair.second.getName() + "," + pair.second.getCategory() + "," + std::to_string(quantity) + "," + std::to_string(price));
            ErrorConsoleUI::displaySuccessMessage("Product updated successfully!");
            return;
        }
    }

    ErrorConsoleUI::displayError("Product not found with ID: " + id, ErrorLevel::ERROR);
}

void Inventory::updateStock(const std::string& id, int quantityChange) {
    loadInventory();
    
    auto it = products.find(id);
    if (it == products.end()) {
        ErrorConsoleUI::displayError("Product not found with ID: " + id, ErrorLevel::ERROR);
        return;
    }

    Product& product = it->second;
    int currentQuantity = product.getQuantity();
    int newQuantity = currentQuantity + quantityChange;

    if (quantityChange < 0 && newQuantity < 0) {
        ErrorConsoleUI::displayError("Insufficient stock for product: " + product.getName() +
                           ". Current stock: " + std::to_string(currentQuantity) + 
                           ", attempted to deduct: " + std::to_string(-quantityChange), 
                           ErrorLevel::ERROR);
        return;
    }

    product.setQuantity(newQuantity);
    
    std::cout << "Updating " << product.getName() 
              << " from " << currentQuantity 
              << " to " << newQuantity 
              << " (change: " << quantityChange << ")" << std::endl;

    FileManager::updateInventory(inventoryFileName, id, 
        id + "," + product.getName() + "," + product.getCategory() + "," + 
        std::to_string(newQuantity) + "," + std::to_string(product.getPrice()));
}

void Inventory::loadInventory() {
    std::vector<std::string> productLines = FileManager::readToInventory(inventoryFileName);

    this->products.clear();

    for(const auto& product : productLines) {
        std::vector<std::string> fields = Utils::splitStringByComma(product);

        this->products.emplace(
            fields[0],  
            Product {
                fields[0],       
                fields[1],       
                fields[2],       
                Utils::stringToInt(fields[3]),  
                Utils::stringToDouble(fields[4]) 
            }
        );

    }
}

double Inventory::inventoryValue() const {
    double total = 0;

    for(auto& product : products) {
        total += (product.second.getQuantity() * product.second.getPrice());
    }

    return total;
}
