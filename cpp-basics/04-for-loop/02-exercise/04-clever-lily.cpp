//
// Created by tonytech on 12/15/2024.
//

#include <iostream>

int main() {
    int age, toy_price;
    double washing_machine_price;

    std::cin >> age >> washing_machine_price >> toy_price;

    double saved_money = 0;

    for (int year = 1; year <= age; year++) {
        if (year % 2 == 0) {
            saved_money += 10 * year / 2 - 1;
        } else {
            saved_money += toy_price;
        }
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    if (saved_money >= washing_machine_price) {
        std::cout << "Yes! " << saved_money - washing_machine_price << std::endl;
    } else {
        std::cout << "No! " << washing_machine_price - saved_money << std::endl;
    }

    return 0;
}
