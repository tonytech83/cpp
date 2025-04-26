//
// Created by TonyTech on 3.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int voucher, tickets_purchased = 0, other_purchased = 0;
    cin >> voucher;

    cin.ignore();
    string input;
    getline(cin, input);

    while (input != "End") {
        int price = 0;
        bool is_ticket = false;

        if (input.size() > 8) {
            price += int(input[0]) + int(input[1]);
            is_ticket = true;
        } else {
            price += int(input[0]);
        }

        if (price <= voucher) {
            voucher -= price;
            if (is_ticket) {
                tickets_purchased++;
            } else {
                other_purchased++;
            }
        } else {
            break;
        }

        getline(cin, input);
    }

    cout << tickets_purchased << endl;
    cout << other_purchased << endl;

    return 0;
}
