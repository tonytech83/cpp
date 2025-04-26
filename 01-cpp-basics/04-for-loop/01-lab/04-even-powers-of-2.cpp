//
// Created by tonytech on 12/15/2024.
//
#include <cmath>
#include <iostream>

int main() {
    int number;
    std::cin >> number;

    for (int i = 0; i <= number; i += 2) {
        std::cout << pow(2, i) << std::endl;
    }

    return 0;
}
