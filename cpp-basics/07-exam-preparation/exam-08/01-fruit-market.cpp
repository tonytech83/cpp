//
// Created by TonyTech on 13.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    double strawberry_price, bananas_count, oranges_count, raspberries_count, strawberries_count;
    cin >> strawberry_price >> bananas_count >> oranges_count >> raspberries_count >> strawberries_count;

    const double raspberry_price = strawberry_price / 2;
    const double orange_price = raspberry_price * 0.6;
    const double banana_price = raspberry_price * 0.2;

    const double total = strawberry_price * strawberries_count + banana_price * bananas_count + orange_price * oranges_count +
                   raspberry_price * raspberries_count;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << total << endl;

    return 0;
}
