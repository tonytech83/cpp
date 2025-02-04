//
// Created by tonytech on 12/22/2024.
//

#include <iostream>
using namespace std;

int main() {
    double balance;
    cin >> balance;
    int balance_in_coins = balance * 100;
    int coins_count = 0;

    while (balance_in_coins > 0) {

        if (balance_in_coins / 200) {
            balance_in_coins -= 200;
        } else if (balance_in_coins / 100) {
            balance_in_coins -= 100;
        } else if (balance_in_coins / 50) {
            balance_in_coins -= 50;
        } else if (balance_in_coins / 20) {
            balance_in_coins -= 20;
        } else if (balance_in_coins / 10) {
            balance_in_coins -= 10;
        } else if (balance_in_coins / 5) {
            balance_in_coins -= 5;
        } else if (balance_in_coins / 2) {
            balance_in_coins -= 2;
        } else if (balance_in_coins / 1) {
            balance_in_coins--;
        }
        coins_count++;
    }

    cout << coins_count << endl;

    return 0;
}
