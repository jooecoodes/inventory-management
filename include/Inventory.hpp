#pragma once

#include "FileManager.hpp"
#include "Product.hpp"
#include <string>
#include <map>

class Inventory {
    private:
        std::string inventoryFileName; 
        std::map<std::string, Product> products; 

    public:
        Inventory();
        void addProduct(const std::string& id, const std::string& name, const std::string& category, int quantity, double price);
        void removeProduct(const std::string& id);
        void displayInventory() const;
        void searchProduct(const std::string& id) const;
        void updateProduct(const std::string& id, int quantity, double price);
};