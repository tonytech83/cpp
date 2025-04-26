//
// Created by TonyTech on 20.12.2024 г..
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int num = 1;
    for (int i = 1; num <= n; i++) {
        std::cout << num << std::endl;
        num = num * 2 + 1;
    }
}
