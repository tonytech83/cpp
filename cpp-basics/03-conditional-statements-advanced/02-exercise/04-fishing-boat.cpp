#include <iostream>
#include <string>

int main() {
    int budget, fishman_count;
    std::string season;

    std::cin >> budget >> season >> fishman_count;

    double price;

    if (season == "Spring") {
        price = 3000;
    } else if (season == "Winter") {
        price = 2600;
    } else {
        price = 4200;
    }

    if (fishman_count <= 6) {
        price *= 0.9;
    } else if (fishman_count > 6 && fishman_count <= 11) {
        price *= 0.85;
    } else {
        price *= 0.75;
    }

    if (fishman_count % 2 == 0 && season != "Autumn") {
        price *= 0.95;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    if (budget >= price) {
        std::cout << "Yes! You have " << budget - price << " leva left." << std::endl;
    } else {
        std::cout << "Not enough money! You need " << price - budget << " leva." << std::endl;
    }

    return 0;
}
