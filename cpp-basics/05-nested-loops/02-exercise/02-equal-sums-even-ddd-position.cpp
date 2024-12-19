//
// Created by anton.petrov on 19.12.2024.
//

#include <iostream>
#include <string>

int main() {
    int first_number, second_number;
    std::cin >> first_number >> second_number;

    for (int current_number = first_number; current_number <= second_number; current_number++) {
        int odd_sum = 0;
        int even_sum = 0;

        std::string current_number_to_str = std::to_string(current_number);

        for (int j = 0; j < 6; j++) {
            if (j % 2 == 0) {
                even_sum += current_number_to_str[j] - '0';
            } else {
                odd_sum += current_number_to_str[j] - '0';
            }
        }
        if (even_sum == odd_sum) {
            std::cout << current_number_to_str << " ";
        }
    }

    return 0;
}
