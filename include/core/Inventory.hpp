#pragma once

#include "../utils/FileManager.hpp"
#include "Product.hpp"
#include <string>
#include <map>

class Inventory {
    private:
        std::string inventoryFileName; 
        std::map<std::string, Product> products;

    public:
        Inventory(std::string filePath);
        void addProduct(const std::string& name, const std::string& category, int quantity, double price);
        void removeProduct(const std::string& id);
        void displayInventory();
        void searchProductByName(const std::string& name);
        void searchProductByID(const std::string& id);
        void updateProduct(const std::string& id, const std::string& name,const std::string& category, int quantity, double price);
        void updateStock(const std::string& id, int quantityChange);
        void loadInventory();
        double inventoryValue() const;
};