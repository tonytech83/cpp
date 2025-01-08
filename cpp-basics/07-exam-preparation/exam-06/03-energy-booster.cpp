//
// Created by TonyTech on 8.1.2025 г..
//

#include "iostream"
using namespace std;

int main() {
    string fruit_type, set_type;
    int ordered_gels;
    cin >> fruit_type >> set_type >> ordered_gels;

    double price = 0.0;

    if (fruit_type == "Watermelon") {
        if (set_type == "small") {
            price = 56.00 * 2;
        } else {
            price = 28.7 * 5;
        }
    } else if (fruit_type == "Mango") {
        if (set_type == "small") {
            price = 36.66 * 2;
        } else {
            price = 19.60 * 5;
        }
    } else if (fruit_type == "Pineapple") {
        if (set_type == "small") {
            price = 42.10 * 2;
        } else {
            price = 24.8 * 5;
        }
    } else {
        if (set_type == "small") {
            price = 20 * 2;
        } else {
            price = 15.2 * 5;
        }
    }

    double order_price = price * ordered_gels;

    if (order_price >= 400 && order_price <= 1000) {
        order_price *= 0.85;
    } else if (order_price > 1000) {
        order_price *= 0.5;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << order_price << " lv." << endl;

    return 0;
}
