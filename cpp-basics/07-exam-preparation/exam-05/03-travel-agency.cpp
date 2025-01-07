//
// Created by TonyTech on 7.1.2025 г..
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string town, packet_type, is_vip;
    int days;
    cin >> town >> packet_type >> is_vip >> days;

    vector<string> valid_towns = {"Bansko", "Borovets", "Varna", "Burgas"};
    if (find(valid_towns.begin(), valid_towns.end(), town) == valid_towns.end()) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    if (days <= 0) {
        cout << "Days must be positive number!" << endl;
        return 0;
    }

    double price;

    if (town == "Bansko" || town == "Borovets") {
        if (packet_type == "withEquipment") {
            price = 100.00;
            if (is_vip == "yes") {
                price *= 0.9;
            }
        } else if (packet_type == "noEquipment") {
            price = 80.00;
            if (is_vip == "yes") {
                price *= 0.95;
            }
        } else {
            cout << "Invalid input!" << endl;
            return 0;
        }
    } else if (town == "Varna" || town == "Burgas") {
        if (packet_type == "withBreakfast") {
            price = 130.00;
            if (is_vip == "yes") {
                price *= 0.88;
            }
        } else if (packet_type == "noBreakfast") {
            price = 100.00;
            if (is_vip == "yes") {
                price *= 0.93;
            }
        } else {
            cout << "Invalid input!" << endl;
            return 0;
        }
    }

    double total_cost = 0.0;
    if (days > 7) {
        total_cost = (days - 1) * price;
    } else {
        total_cost = days * price;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The price is " << total_cost << "lv! Have a nice time!" << endl;

    return 0;
}
