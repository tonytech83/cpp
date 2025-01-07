//
// Created by TonyTech on 7.1.2025 г..
//

#include <iostream>
using namespace std;


int main() {
    double budget, night_price;
    int nights, other_percent;
    cin >> budget >> nights >> night_price >> other_percent;

    if (nights > 7) {
        night_price *= 0.95;
    }

    static double vacation_cost = nights * night_price + budget * other_percent / 100;

    cout.setf(ios::fixed);
    cout.precision(2);
    if (budget >= vacation_cost) {
        cout << "Ivanovi will be left with " << budget - vacation_cost << " leva after vacation." << endl;
    } else {
        cout << vacation_cost - budget << " leva needed." << endl;
    }

    return 0;
}
