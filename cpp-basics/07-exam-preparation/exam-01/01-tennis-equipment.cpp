//
// Created by TonyTech on 23.12.2024 г..
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double tennis_racket_price;
    int tennis_racket_count, tennis_sneakers_count;
    cin >> tennis_racket_price >> tennis_racket_count >> tennis_sneakers_count;

    const double tennis_sneakers_price = tennis_racket_price / 6;
    double total_price = tennis_racket_price * tennis_racket_count + tennis_sneakers_price * tennis_sneakers_count;
    total_price *= 1.2;

    cout << "Price to be paid by Djokovic " << static_cast<int>(total_price / 8) << endl;
    cout << "Price to be paid by sponsors " << ceil(total_price * 7 / 8) << endl;

    return 0;
}
