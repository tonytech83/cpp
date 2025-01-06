//
// Created by TonyTech on 6.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    double budget, price;
    string destination, season;
    int days;
    cin >> budget >> destination >> season >> days;

    if (destination == "Dubai") {
        if (season == "Winter") {
            price = 45000.00 * 0.7;
        } else {
            price = 40000.00 * 0.7;
        }
    } else if (destination == "Sofia") {
        if (season == "Winter") {
            price = 17000.00 * 1.25;
        } else {
            price = 12500.00 * 1.25;
        }
    } else {
        if (season == "Winter") {
            price = 24000.00;
        } else {
            price = 20250.00;
        }
    }

    const double total = price * days;

    cout.setf(ios::fixed);
    cout.precision(2);
    if (budget > total) {
        cout << "The budget for the movie is enough! We have " << budget - total << " leva left!" << endl;
    } else {
        cout << "The director needs " << total - budget << " leva more!" << endl;
    }

    return 0;
}
