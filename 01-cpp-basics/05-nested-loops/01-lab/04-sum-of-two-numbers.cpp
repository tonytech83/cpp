//
// Created by tonytech on 12/17/2024.
//

#include <iostream>


int main() {
    int start, end, magic_number;
    std::cin >> start >> end >> magic_number;

    int idx = 0;
    bool found = false;
    int num1 = 0, num2 = 0;

    for (num1 = start; num1 <= end; num1++) {
        for (num2 = start; num2 <= end; num2++) {
            idx++;
            if (num1 + num2 == magic_number) {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (found) {
        std::cout << "Combination N:" << idx << " ";
        std::cout << "(" << num1 << " + " << num2 << " = " << magic_number <<")"<< std::endl;
    } else {
        std::cout << idx << " combinations - neither equals " << magic_number << std::endl;
    }

    return 0;
}
