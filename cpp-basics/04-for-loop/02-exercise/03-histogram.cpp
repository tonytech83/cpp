//
// Created by tonytech on 12/15/2024.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    double p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;

    for (int i = 0; i < n; i++) {
        int current;
        std::cin >> current;

        if (current < 200) {
            p1 += 1;
        } else if (current < 400) {
            p2 += 1;
        } else if (current < 600) {
            p3 += 1;
        } else if (current < 800) {
            p4 += 1;
        } else {
            p5 += 1;
        }
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << p1 / n * 100 << "%" << std::endl;
    std::cout << p2 / n * 100 << "%" << std::endl;
    std::cout << p3 / n * 100 << "%" << std::endl;
    std::cout << p4 / n * 100 << "%" << std::endl;
    std::cout << p5 / n * 100 << "%" << std::endl;

    return 0;
}
