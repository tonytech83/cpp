//
// Created by tonytech on 12/17/2024.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int counter = 0;

    for (int x1 = 0; x1 <= n; x1++) {
        for (int x2 = 0; x2 <= n; x2++) {
            for (int x3 = 0; x3 <= n; x3++) {
                if (x1 + x2 + x3 == n) {
                    counter++;
                }
            }
        }
    }

    std::cout << counter;

    return 0;
}