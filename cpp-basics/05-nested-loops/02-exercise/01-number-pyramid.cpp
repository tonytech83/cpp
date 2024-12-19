//
// Created by anton.petrov on 19.12.2024.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int current = 1;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col < row + 1; col++) {
            if (current > n) {
                break;
            }
            std::cout << current << " ";
            current++;
        }
        std::cout << '\n';
    }
}
