#pragma once

#include <string>
#include <vector>

class FileManager {
    public:
        static std::vector<std::string> readToInventory(const std::string& filePath);
        static void writeToInventory(const std::string& filePath, const std::string& data);
        static void deleteFromInventory(const std::string& filePath, const std::string& id);
        static void updateInventory(const std::string& filePath, const std::string& id, const std::string& data);
};