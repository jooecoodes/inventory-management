#pragma once

#include <string>

class Product {
    private:
        std::string id;
        std::string name;
        std::string category;
        int quantity;
        double price;

    public:
        Product();
        void display() const;
        std::string getID() const;
        std::string getName() const;
        std::string getCategory() const;
        int getQuantity() const;
        double getPrice() const;
        void setID(const std::string& id);
        void setName(const std::string& name);
        void setCategory(const std::string& category);
        void setQuantity(int quantity);
        void setPrice(double price);
};