//
// Created by tonytech on 12/15/2024.
//
#include <iostream>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);

    int sum = 0;

    for (const auto c: text) {
        if (c == 'a') sum += 1;
        if (c == 'e') sum += 2;
        if (c == 'i') sum += 3;
        if (c == 'o') sum += 4;
        if (c == 'u') sum += 5;
    }

    std::cout << sum << std::endl;

    return 0;
}