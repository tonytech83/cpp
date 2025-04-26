//
// Created by TonyTech on 13.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    double budget, cost = 0.0;
    cin >> budget;

    int counter = 0;

    cin.ignore();
    string equipment;
    getline(cin, equipment);

    while (equipment != "Stop") {
        double equipment_price;
        cin >> equipment_price;

        counter++;

        if (counter % 3 == 0) {
            equipment_price *= 0.5;
        }

        if (budget - cost < equipment_price) {
            cost += equipment_price;
            break;
        }

        cost += equipment_price;
        cin.ignore();
        getline(cin, equipment);
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    if (budget >= cost) {
        cout << "You bought " << counter << " products for " << cost << " leva." << endl;
    } else {
        cout << "You don't have enough money!" << endl;
        cout << "You need " << cost - budget << " leva!" << endl;
    }

    return 0;
}
