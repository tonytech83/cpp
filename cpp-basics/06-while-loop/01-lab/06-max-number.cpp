//
// Created by TonyTech on 20.12.2024 г..
//

#include <iostream>
#include <string>
#include <climits>

int main() {
    int largest_number = INT_MIN;

    while (true) {
        std::string number;
        std::cin >> number;

        if (number == "Stop")
            break;

        if (std::stoi(number) > largest_number) {
            largest_number = std::stoi(number);
        }
    }

    std::cout << largest_number << std::endl;

    return 0;
}
