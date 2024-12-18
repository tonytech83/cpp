//
// Created by anton.petrov on 18.12.2024.
//

#include <iostream>
#include <string>

int main() {
    std::string destination;
    std::cin >> destination;

    while (destination != "End") {
        double saved_money = 0.0;

        double destination_budget;
        std::cin >> destination_budget;

        while (destination_budget > saved_money) {
            double salary;
            std::cin >> salary;
            saved_money += salary;
        }
        std::cout << "Going to " << destination << "!" << std::endl;

        std::cin >> destination;
    }

    return 0;
}
