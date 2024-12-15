//
// Created by tonytech on 12/15/2024.
//
#include <climits>
#include <iostream>

int main() {
    int n, input;
    std::cin >> n >> input;

    int min = input;
    int max = input;

    for (int i = 1; i < n; i++) {
        std::cin >> input;

        if (input < min) {
            min = input;
        } else if (input > max) {
            max = input;
        }
    }

    std::cout << "Max number: " << max << std::endl;
    std::cout << "Min number: " << min << std::endl;

    return 0;
}
