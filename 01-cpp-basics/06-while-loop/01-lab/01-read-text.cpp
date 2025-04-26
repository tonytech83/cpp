//
// Created by TonyTech on 20.12.2024 г..
//

#include <iostream>
#include <string>

int main() {
    std::string text;
    std::cin >> text;

    while (text != "Stop") {
        std::cout << text << std::endl;
        std::cin >> text;
    }

    return 0;
}
