#pragma once

#include "../core/Inventory.hpp"
#include <string>

class InputHandler {
    public:
        static void addProdInputHandler(std::string& name, std::string& category, int& quantity, double& price);
        static void removeProdInputHandler(std::string& id);
        static void searchProdInputHandler(Inventory &Inventory);
        static void updateProdInputHandler(std::string& id, std::string& name, std::string& category, int& quantity, double& price, Inventory& inventory);
};