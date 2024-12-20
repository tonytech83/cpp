//
// Created by TonyTech on 20.12.2024 г..
//

#include <iostream>

int main() {
    int number, sum = 0;
    std::cin >> number;

    while (sum <  number) {
        int input;
        std::cin >> input;
        sum += input;
    }

    std::cout << sum << std::endl;

    return 0;
}