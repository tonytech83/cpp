//
// Created by TonyTech on 3.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    double budget, clothes_per_extra;
    int extras_count;
    cin >> budget >> extras_count >> clothes_per_extra;

    const double decor_price = budget * 0.1;
    double clothes_price = extras_count * clothes_per_extra;
    if (extras_count > 150) {
        clothes_price *= 0.9;
    }

    double total = decor_price + clothes_price;

    cout.setf(ios::fixed);
    cout.precision(2);

    if (budget >= total) {
        cout << "Action!" << endl << "Wingard starts filming with " << budget - total << " leva left." << endl;
    } else {
        cout << "Not enough money!" << endl << "Wingard needs " << total - budget << " leva more." << endl;
    }

    return 0;
}
