//
// Created by TonyTech on 3.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    int rent_hall;
    cin >> rent_hall;

    const double statuettes_price = rent_hall * 0.7;
    const double catering_price = statuettes_price * 0.85;
    const double sound_price = catering_price / 2;

    const double total_price = rent_hall + statuettes_price + catering_price + sound_price;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << total_price << endl;

    return 0;
}
