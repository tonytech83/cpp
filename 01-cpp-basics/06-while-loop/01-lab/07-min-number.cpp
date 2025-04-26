//
// Created by TonyTech on 20.12.2024 г..
//

#include <climits>
#include <iostream>
#include <string>

int main() {
    int smallest_number = INT_MAX;

    while (true) {
        std::string input;
        std::cin >> input;

        if (input == "Stop")
            break;

        if (std::stoi(input) < smallest_number) {
            smallest_number = std::stoi(input);
        }
    }

    std::cout << smallest_number << std::endl;

    return 0;
}
