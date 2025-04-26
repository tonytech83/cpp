//
// Created by TonyTech on 19.12.2024 г..
//

#include <iostream>
#include <string>

bool is_prime(const int current_number) {
    const int number = current_number;
    int cnt = 0;
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            cnt++;
        }
    }

    if (cnt > 2) {
        return false;
    }

    return true;
};

int main() {
    std::string number;
    std::cin >> number;

    int prime_sum = 0, non_prime_sum = 0;

    while (number != "stop") {
        const int current_number = std::stoi(number);

        if (current_number < 0) {
            std::cout << "Number is negative." << std::endl;
        } else {
            if (is_prime(current_number)) {
                prime_sum += current_number;
            } else {
                non_prime_sum += current_number;
            }
        }
        std::cin >> number;
    }

    std::cout << "Sum of all prime numbers is: " << prime_sum << std::endl;
    std::cout << "Sum of all non prime numbers is: " << non_prime_sum << std::endl;

    return 0;
}
