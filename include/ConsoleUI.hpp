#pragma once
#include <string>

class ConsoleUI {
    public:
        void displayMenuUI() const;
        void displayAddProdUI();
        void displayRemoveProdUI() const;
        void displayInventoryUI() const;
        void displaySearchProdUI() const;
        void displayUpdateProdUI() const;
        void displayExitUI() const;
        void displayFields();
        void displayEnterChoiceForLoop();

        static void displayProduct(const std::string& id, const std::string& name,
                                const std::string& category, int quantity, double price);
};