//
// Created by tonytech on 12/15/2024.
//
#include <cmath>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int left = 0, right = 0;

    for (int i = 1; i <= n * 2; i++) {
        int current_number;
        std::cin >> current_number;

        if (i <= n) {
            left += current_number;
        } else {
            right += current_number;
        }
    }

    if (left == right) {
        std::cout << "Yes, sum = " << right << std::endl;
    } else {
        std::cout << "No, diff = " << std::abs(left - right) << std::endl;
    }

    return 0;
}
