#include <iostream>
#include "../include/Utils.h"
#include "../include/Product.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "This is a test" << std::endl;

    Utils utils;
    utils.print();

    Product product;
    product.display();
    return 0;
}