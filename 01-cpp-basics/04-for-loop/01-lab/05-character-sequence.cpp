//
// Created by tonytech on 12/15/2024.
//
#include <iostream>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);

    for (const auto chr : text) {
        std::cout << chr << std::endl;

    }

    return 0;
}