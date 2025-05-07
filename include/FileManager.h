#pragma once

#include <string>

class FileManager {
    public:
        FileManager();
        ~FileManager();
        void loadInventory(const std::string& filename);
        void saveInventory(const std::string& filename) const;
        void loadProducts(const std::string& filename);
        void saveProducts(const std::string& filename) const;
};