//
// Created by TonyTech on 6.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    double budget, spend_money = 0.0;
    cin >> budget;
    cin.ignore();

    string actor_name;
    getline(cin, actor_name);

    while (actor_name != "ACTION") {
        double actor_salary;

        if (actor_name.size() > 15) {
            actor_salary = (budget - spend_money) * 0.2;
        } else {
            cin >> actor_salary;
            cin.ignore();
        }

        spend_money += actor_salary;

        if (spend_money > budget) {
            break;
        }

        getline(cin, actor_name);
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    if (budget > spend_money) {
        cout << "We are left with " << budget - spend_money << " leva." << endl;
    } else {
        cout << "We need " << spend_money - budget << " leva for our actors." << endl;
    }

    return 0;
}
