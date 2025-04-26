//
// Created by TonyTech on 8.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    double btc, chy, percent;
    cin >> btc >> chy >> percent;

    const double eur = (btc * 1168 / 1.95 + chy * 0.15 * 1.76 / 1.95) * (1 - percent / 100);

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << eur << endl;

    return 0;
}
