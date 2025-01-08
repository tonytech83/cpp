//
// Created by TonyTech on 8.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    double hall_rent;
    cin >> hall_rent;

    const double cake_price = hall_rent * 0.2;
    const double drinks_price = cake_price * 0.55;
    const double animator_price = hall_rent / 3;

    const double total_price = hall_rent + cake_price + animator_price + drinks_price;

    cout << total_price << endl;

    return 0;
}
