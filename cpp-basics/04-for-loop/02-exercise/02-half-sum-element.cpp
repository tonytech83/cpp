//
// Created by tonytech on 12/15/2024.
//
#include <iostream>
#include <climits>

int main() {
    int n;
    std::cin >> n;

    int sum = 0;
    int biggest = INT_MIN;

    for (int i = 0; i < n; i++) {
        int current;
        std::cin >> current;

        if (current > biggest) {
            biggest = current;
        }

        sum += current;
    }

    if (sum - biggest == biggest) {
        std::cout << "Yes" << std::endl;
        std::cout << "Sum = " << biggest << std::endl;
    } else {
        std::cout << "No" << std::endl;
        std::cout << "Diff = " << std::abs(biggest - (sum - biggest)) << std::endl;
    }

    return 0;
}
