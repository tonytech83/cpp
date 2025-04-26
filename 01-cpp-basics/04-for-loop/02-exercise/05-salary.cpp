//
// Created by anton.petrov on 16.12.2024.
//

#include <iostream>
#include <string>

int main () {
    int open_tabs, salary;
    std::cin >> open_tabs >> salary;

    for (int i = 0; i < open_tabs; i++) {
        std::string current_tab;
        std::cin >> current_tab;

        if (current_tab == "Facebook") {
            salary -= 150;
        } else if (current_tab == "Instagram") {
            salary -= 100;
        } else if (current_tab == "Reddit") {
            salary -= 50;
        }

        if (salary <= 0) {
            std::cout << "You have lost your salary." << std::endl;
            break;
        }
    }

    if (salary > 0) std::cout << salary << std::endl;

    return 0;
}