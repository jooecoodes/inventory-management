#pragma once

#include <string>

class Inventory {
    public:
        Inventory();
        ~Inventory();
        void addProduct(const std::string& id, const std::string& name, const std::string& category, int quantity, double price);
        void removeProduct(const std::string& id);
        void displayInventory() const;
        void searchProduct(const std::string& id) const;
        void updateProduct(const std::string& id, int quantity, double price);
};