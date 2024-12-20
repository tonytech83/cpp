//
// Created by TonyTech on 20.12.2024 г..
//

#include <iostream>
#include <string>

int main() {
    double balance = 0;
    std::string input;
    std::cin >> input;

    while (true) {
        if (input == "NoMoreMoney") {
            break;
        }
        if (std::stod(input) < 0) {
            std::cout << "Invalid operation!" << std::endl;
            break;
        }

        balance += std::stod(input);

        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << "Increase: " << std::stod(input) << std::endl;
        std::cin >> input;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "Total: " << balance << std::endl;

    return 0;
}
