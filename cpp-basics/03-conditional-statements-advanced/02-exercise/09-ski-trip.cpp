#include <iostream>
#include <limits>
#include <string>

int main() {
    int days_of_stay;
    std::string rating, room_type;

    std::cin >> days_of_stay;
    // Clear the leftover newline character
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, room_type);
    std::cin >> rating;

    double price;

    if (room_type == "room for one person") {
        price = (days_of_stay - 1) * 18.00;
    } else if (room_type == "apartment") {
        if (days_of_stay < 10) {
            price = (days_of_stay - 1) * 25.00 * 0.7;
        } else if (days_of_stay >= 10 && days_of_stay <= 15) {
            price = (days_of_stay - 1) * 25.00 * 0.65;
        } else {
            price = (days_of_stay - 1) * 25.00 * 0.5;
        }
    } else {
        if (days_of_stay < 10) {
            price = (days_of_stay - 1) * 35.00 * 0.9;
        } else if (days_of_stay >= 10 && days_of_stay <= 15) {
            price = (days_of_stay - 1) * 35.00 * 0.85;
        } else {
            price = (days_of_stay - 1) * 35.00 * 0.8;
        }
    }

    if (rating == "positive") {
        price *= 1.25;
    } else {
        price *= 0.9;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << price << std::endl;

    return 0;
}
