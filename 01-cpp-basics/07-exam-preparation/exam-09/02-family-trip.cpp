//
// Created by tonytech on 3/15/25.
//
#include <iostream>
using namespace std;

int main() {
    double budget, overnightStayPrice;
    int overnightStayCount, additionalCostPercent;

    cin >> budget >> overnightStayCount >> overnightStayPrice >> additionalCostPercent;

    if (overnightStayCount > 7) {
        overnightStayPrice *= 0.95;
    }

    const double tripCost = overnightStayCount * overnightStayPrice + (budget * additionalCostPercent / 100.0);

    cout.setf(ios::fixed);
    cout.precision(2);
    if (budget >= tripCost) {
        cout << "Ivanovi will be left with " << budget - tripCost << " leva after vacation." << endl;
    } else {
        cout << tripCost - budget << " leva needed." << endl;
    }

    return 0;
}
