#include <iostream>
#include <string>


int main() {
    std::string fruit;
    std::string day;
    double quantity;
    std::cin >> fruit >> day >> quantity;

    double price;

    if (day == "Saturday" or day == "Sunday") {
        if (fruit == "banana") {
            price = 2.70;
        } else if (fruit == "apple") {
            price = 1.25;
        } else if (fruit == "orange") {
            price = 0.9;
        } else if (fruit == "grapefruit") {
            price = 1.60;
        } else if (fruit == "kiwi") {
            price = 3.00;
        } else if (fruit == "pineapple") {
            price = 5.60;
        } else if (fruit == "grapes") {
            price = 4.2;
        } else {
            std::cout << "error\n";
            return 0;
        }
    } else if (day == "Monday" or day == "Tuesday" or day == "Wednesday" or day == "Thursday" or day == "Friday") {
        if (fruit == "banana") {
            price = 2.50;
        } else if (fruit == "apple") {
            price = 1.2;
        } else if (fruit == "orange") {
            price = 0.85;
        } else if (fruit == "grapefruit") {
            price = 1.45;
        } else if (fruit == "kiwi") {
            price = 2.7;
        } else if (fruit == "pineapple") {
            price = 5.50;
        } else if (fruit == "grapes") {
            price = 3.85;
        } else {
            std::cout << "error\n";
            return 0;
        }
    } else {
        std::cout << "error\n";
        return 0;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << price * quantity << std::endl;

    return 0;
}
