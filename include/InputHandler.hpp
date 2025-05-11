#pragma once
#include <string>

class InputHandler {
    public:
        static void addProdInputHandler(std::string& name, std::string category, int& quantity, double& price);
        static void removeProdInputHandler(std::string& id);
        static void searchProdInputHandler(std::string& id);
        static void updateProdInputHandler(std::string id, std::string& name, std::string& category, int& quantity, double& price);
};