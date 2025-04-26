//
// Created by TonyTech on 7.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string drink_type, sugar_level;
    int drinks_number;
    cin >> drink_type >> sugar_level >> drinks_number;

    double price = 0.0;

    if (drink_type == "Espresso") {
        if (sugar_level == "Without") {
            price = 0.9 * 0.65;
        } else if (sugar_level == "Normal") {
            price = 1.00;
        } else {
            price = 1.2;
        }

        if (drinks_number >= 5) {
            price *= 0.75;
        }

    } else if (drink_type == "Cappuccino") {
        if (sugar_level == "Without") {
            price = 1 * 0.65;
        } else if (sugar_level == "Normal") {
            price = 1.20;
        } else {
            price = 1.6;
        }
    } else {
        if (sugar_level == "Without") {
            price = 0.5 * 0.65;
        } else if (sugar_level == "Normal") {
            price = 0.6;
        } else {
            price = 0.7;
        }
    }

    double total_cost = price * drinks_number;

    if (total_cost > 15) {
        total_cost *= 0.8;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "You bought " << drinks_number << " cups of " << drink_type << " for " << total_cost << " lv." << endl;

    return 0;
}
