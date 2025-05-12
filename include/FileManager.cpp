#include "FileManager.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

namespace {
    namespace fs = std::filesystem;
    const fs::path dataDir = "data";

    auto fileOpenModeRead = std::ios::in;
    auto fileOpenModeAppend = std::ios::app;
    auto fileOpenModeTruncate = std::ios::trunc;

    inline void checkDirExist() {
        if (!fs::exists(dataDir)) {
            fs::create_directory(dataDir);
        }
    }
}

std::vector<std::string> FileManager::readToInventory(const std::string& fileName) {
    
    checkDirExist();

    fs::path filePath = dataDir / fileName;
    std::ifstream inFile(filePath);
    std::vector<std::string> inventory;
    std::string line;

    if (inFile.is_open()) {
        while(std::getline(inFile, line)) {
            inventory.push_back(line);
        }
    } else {
        std::cout << "Unable to open file: " << filePath << std::endl;
    }

    inFile.close();

    return inventory;
}

void FileManager::writeToInventory(const std::string& fileName, const std::string& data) {
    
    checkDirExist();

    fs::path filePath = dataDir / fileName;
    std::ofstream outFile(filePath, fileOpenModeAppend);

    if(outFile.is_open()) {
        outFile << data << std::endl;
    } else {
        std::cout << "Unable to open file: " << filePath << std::endl;
    }

    outFile.close();
}

void FileManager::deleteFromInventory(const std::string& fileName, const std::string& id) {
    
    checkDirExist();

    fs::path filePath = dataDir / fileName;
    std::ifstream inFile(filePath);
    std::vector<std::string> newInventory;
    std::string line;

    if(inFile.is_open()) {
        while(std::getline(inFile, line)) {
            if(line.find(id) == std::string::npos) {
                newInventory.push_back(line);
            }
        }
    } else {
        std::cout << "Unable to open file: " << filePath << std::endl;
    }

    inFile.close();
    std::ofstream outFile(filePath, fileOpenModeTruncate);
    if(outFile.is_open()) {
        for (const auto& product : newInventory) {
            outFile << product << std::endl;
        }
    } else {
        std::cout << "Unable to open file: " << filePath << std::endl;
    }
    outFile.close();
}

void FileManager::updateInventory(const std::string& fileName, const std::string& id, const std::string& data) {
    
    checkDirExist();

    fs::path filePath = dataDir / fileName;
    std::ifstream inFile(filePath);
    std::vector<std::string> newInventory;
    std::string line;

    if(inFile.is_open()) {
        while(std::getline(inFile, line)) {
            if(line.find(id) != std::string::npos) {
                newInventory.push_back(data);
            } else {
                newInventory.push_back(line);
            }
        }
    } else {
        std::cout << "Unable to open file: " << filePath << std::endl;
    }

    inFile.close();

    std::ofstream outFile(filePath, fileOpenModeTruncate);
    
    if(outFile.is_open()) {
        for (const auto& product : newInventory) {
            outFile << product << std::endl;
        }
    } else {
        std::cout << "Unable to open file: " << filePath << std::endl;
    }

    outFile.close();
}