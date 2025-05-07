#include <iostream>
#include "../include/Utils.hpp"
#include "../include/Product.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "This is a test" << std::endl;

    Utils utils;
    utils.print();

    Product product;
    product.display();
    return 0;
}