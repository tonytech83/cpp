//
// Created by tonytech on 12/22/2024.
//

#include <iostream>
#include <string>
using namespace std;

string output(const bool go_to_vacation, const int total_days) {
    if (go_to_vacation) {
        return "You saved the money for " + to_string(total_days) + " days.\n";
    }
    return "You can't save the money.\n" + to_string(total_days) + "\n";
}

int main() {
    double vacation_price, available_money;
    cin >> vacation_price >> available_money;

    int total_days = 0, spend_days = 0;
    bool go_to_vacation = false;

    while (spend_days < 5) {
        string action;
        double money_amount;
        cin >> action >> money_amount;

        total_days++;

        if (action == "save") {
            available_money += money_amount;
            spend_days = 0;
        } else {
            spend_days++;
            if (money_amount > available_money) {
                available_money = 0;
            } else {
                available_money -= money_amount;
            }
        }

        if (available_money >= vacation_price) {
            go_to_vacation = true;
            break;
        }
    }

    cout << output(go_to_vacation, total_days) << endl;

    return 0;
}
