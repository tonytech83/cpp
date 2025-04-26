//
// Created by TonyTech on 23.12.2024 г..
//

#include <iostream>
using namespace std;

int main() {
    double year_tax;
    cin >> year_tax;

    const double sneakers_price = year_tax * 0.6;
    const double clothing_price = sneakers_price * 0.8;
    const double ball = clothing_price / 4;
    const double accessories = ball / 5;

    const double total = year_tax + sneakers_price + clothing_price + ball + accessories;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << total << endl;

    return 0;
}
