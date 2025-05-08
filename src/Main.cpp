#include <iostream>
#include "../include/Utils.hpp"
#include "../include/Product.hpp"
#include "../include/InventoryApp.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "This is a test" << std::endl;

    InventoryApp app;
    app.run();

    return 0;
}