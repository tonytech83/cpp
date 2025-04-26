//
// Created by tonytech on 04/01/25.
//

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int guests_count, budget;
    cin >> guests_count >> budget;

    const int cakes_count = ceil(guests_count / 3.0);
    const int eggs_count = guests_count * 2;

    const double total_cost = cakes_count * 4.0 + eggs_count * 0.45;

    cout.setf(ios::fixed);
    cout.precision(2);
    if (total_cost <= budget) {
        cout << "Lyubo bought " << cakes_count << " Easter bread and " << eggs_count << " eggs." << endl;
        cout << "He has " << budget - total_cost << " lv. left." << endl;
    } else {
        cout << "Lyubo doesn't have enough money." << endl;
        cout << "He needs " << total_cost - budget << " lv. more." << endl;
    }

    return 0;
}
