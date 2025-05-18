#include "FileManager.hpp"
#include "ErrorConsoleUI.hpp"
#include <string>
#include <fstream>
#include <filesystem>

namespace {
    namespace fs = std::filesystem;
    const fs::path dataDir = "data";

    auto fileOpenModeRead = std::ios::in;
    auto fileOpenModeAppend = std::ios::app;
    auto fileOpenModeTruncate = std::ios::trunc;

    inline void checkDirExist() {
        try {
            if (!fs::exists(dataDir)) {
                fs::create_directory(dataDir);
            }
        } catch (const fs::filesystem_error& e) {
            ErrorConsoleUI::displaySystemError("Failed to create data directory: " + std::string(e.what()));
        }
    }
}

std::vector<std::string> FileManager::readToInventory(const std::string& fileName) {
    std::vector<std::string> inventory;
    
    try {
        checkDirExist();
        fs::path filePath = dataDir / fileName;
        std::ifstream inFile(filePath);

        if (!inFile.is_open()) {
            ErrorConsoleUI::displaySystemError("Failed to open file for reading: " + filePath.string());
            return inventory;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            if (!line.empty()) {
                inventory.push_back(line);
            }
        }

        inFile.close();
    } catch (const std::exception& e) {
        ErrorConsoleUI::displaySystemError("Error reading inventory: " + std::string(e.what()));
    }

    return inventory;
}

void FileManager::writeToInventory(const std::string& fileName, const std::string& data) {
    try {
        checkDirExist();
        fs::path filePath = dataDir / fileName;
        std::ofstream outFile(filePath, fileOpenModeAppend);

        if (!outFile.is_open()) {
            ErrorConsoleUI::displaySystemError("Failed to open file for writing: " + filePath.string());
            return;
        }

        outFile << data << std::endl;
        outFile.close();
    } catch (const std::exception& e) {
        ErrorConsoleUI::displaySystemError("Error writing to inventory: " + std::string(e.what()));
    }
}

void FileManager::deleteFromInventory(const std::string& fileName, const std::string& id) {
    try {
        checkDirExist();
        fs::path filePath = dataDir / fileName;
        
        std::ifstream inFile(filePath);
        if (!inFile.is_open()) {
            ErrorConsoleUI::displaySystemError("Failed to open file for reading: " + filePath.string());
            return;
        }

        std::vector<std::string> newInventory;
        std::string line;
        bool found = false;

        while (std::getline(inFile, line)) {
            if (!line.empty() && line.find(id) == std::string::npos) {
                newInventory.push_back(line);
            } else if (!line.empty()) {
                found = true;
            }
        }
        inFile.close();

        if (!found) {
            ErrorConsoleUI::displayError("Product with ID " + id + " not found", ErrorLevel::WARNING);
            return;
        }

        // Write back the updated inventory
        std::ofstream outFile(filePath, fileOpenModeTruncate);
        if (!outFile.is_open()) {
            ErrorConsoleUI::displaySystemError("Failed to open file for writing: " + filePath.string());
            return;
        }

        for (const auto& product : newInventory) {
            outFile << product << std::endl;
        }
        outFile.close();

    } catch (const std::exception& e) {
        ErrorConsoleUI::displaySystemError("Error deleting from inventory: " + std::string(e.what()));
    }
}

void FileManager::updateInventory(const std::string& fileName, const std::string& id, const std::string& data) {
    try {
        checkDirExist();
        fs::path filePath = dataDir / fileName;
        
        std::ifstream inFile(filePath);
        if (!inFile.is_open()) {
            ErrorConsoleUI::displaySystemError("Failed to open file for reading: " + filePath.string());
            return;
        }

        std::vector<std::string> newInventory;
        std::string line;
        bool found = false;

        while (std::getline(inFile, line)) {
            if (!line.empty()) {
                if (line.find(id) != std::string::npos) {
                    newInventory.push_back(data);
                    found = true;
                } else {
                    newInventory.push_back(line);
                }
            }
        }
        inFile.close();

        if (!found) {
            ErrorConsoleUI::displayError("Product with ID " + id + " not found", ErrorLevel::WARNING);
            return;
        }

        std::ofstream outFile(filePath, fileOpenModeTruncate);
        if (!outFile.is_open()) {
            ErrorConsoleUI::displaySystemError("Failed to open file for writing: " + filePath.string());
            return;
        }

        for (const auto& product : newInventory) {
            outFile << product << std::endl;
        }
        outFile.close();

    } catch (const std::exception& e) {
        ErrorConsoleUI::displaySystemError("Error updating inventory: " + std::string(e.what()));
    }
}