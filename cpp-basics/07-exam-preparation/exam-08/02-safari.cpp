//
// Created by TonyTech on 13.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    double budget, fuel;
    string day_of_week;
    cin >> budget >> fuel >> day_of_week;

    double total = fuel * 2.1 + 100;

    if (day_of_week == "Saturday") {
        total *= 0.9;
    } else {
        total *= 0.8;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    if (budget >= total) {
        cout << "Safari time! Money left: " << budget - total << " lv." << endl;
    } else {
        cout << "Not enough money! Money needed: " << total - budget << " lv." << endl;
    }

    return 0;
}
