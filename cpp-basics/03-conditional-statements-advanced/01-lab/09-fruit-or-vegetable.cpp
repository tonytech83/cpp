#include <iostream>

int main() {
    std::string product;
    std::cin >> product;

    if (product == "banana" || product == "apple" || product == "kiwi" || product == "cherry" || product == "lemon" ||
        product == "grapes") {
        std::cout << "fruit" << std::endl;
    } else if (product == "tomato" || product == "cucumber" || product == "papper" || product == "carrot") {
        std::cout << "vegetable" << std::endl;
    } else {
        std::cout << "unknown" << std::endl;
    }
    return 0;
}
