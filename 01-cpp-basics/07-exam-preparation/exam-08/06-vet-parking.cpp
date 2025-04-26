//
// Created by TonyTech on 13.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    int days, hours;
    cin >> days >> hours;

    double total_cost = 0;

    for (int day = 1; day <= days; day++) {
        double tax = 0.0;
        double day_cost = 0.0;
        for (int hour = 1; hour <= hours; hour++) {
            if (day % 2 == 0 && hour % 2 != 0) {
                tax = 2.5;
            } else if (day % 2 != 0 && hour % 2 == 0) {
                tax = 1.25;
            } else {
                tax = 1;
            }
            day_cost += tax;
        }
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Day: " << day << " - " << day_cost << " leva" << endl;
        total_cost += day_cost;
    }

    cout << "Total: " << total_cost << " leva" << endl;

    return 0;
}
