//
// Created by tonytech on 04/01/25.
//

#include <iostream>
using namespace std;

int main() {
    int guest_count;
    double guest_price, budget;
    cin >> guest_count >> guest_price >> budget;

    if (guest_count >= 10 && guest_count <= 15) {
        guest_price *= 0.85;
    } else if (guest_count > 15 && guest_count <= 20) {
        guest_price *= 0.8;
    } else if (guest_count > 20) {
        guest_price *= 0.75;
    }

    const double cake_price = budget * 0.1;
    const double total_cost = guest_count * guest_price + cake_price;

    cout.setf(ios::fixed);
    cout.precision(2);
    if (total_cost <= budget) {
        cout << "It is party time! " << budget - total_cost << " leva left." << endl;
    } else {
        cout << "No party! " << total_cost - budget << " leva needed." << endl;
    }

    return 0;
}
