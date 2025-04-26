//
// Created by tonytech on 12/15/2024.
//
#include <cmath>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int odd_sum = 0, even_sum = 0;

    for (int i = 1; i <= n; i++) {
        int current_num;
        std::cin >> current_num;

        if (i % 2 == 0) {
            odd_sum += current_num;
        } else {
            even_sum += current_num;
        }
    }

    if (odd_sum == even_sum) {
        std::cout << "Yes" << std::endl;
        std::cout << "Sum = " << odd_sum << std::endl;
    } else {
        std::cout << "No" << std::endl;
        std::cout << "Diff = " << abs(odd_sum - even_sum) << std::endl;
    }

    return 0;
}
