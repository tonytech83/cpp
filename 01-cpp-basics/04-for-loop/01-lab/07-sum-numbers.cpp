//
// Created by tonytech on 12/15/2024.
//
#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        int num;
        std::cin >> num;
        sum += num;
    }

    std::cout << sum;

    return 0;
}
