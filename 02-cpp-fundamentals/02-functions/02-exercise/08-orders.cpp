//
// Created by tonytech on 5/6/25.
//
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

double calculateTotalPrice(const string &product, double quantity);

int main() {
    string product;
    int quantity;
    cin >> product >> quantity;

    cout << fixed << setprecision(2) << calculateTotalPrice(product, quantity) << endl;

    return 0;
}

double calculateTotalPrice(const string &product, const double quantity) {
    double price = 0.0;
    if (product == "coffee")
        price = 1.5;
    else if (product == "water")
        price = 1.0;
    else if (product == "coke")
        price = 1.4;
    else if (product == "snacks")
        price = 2.0;

    return quantity * price;
}
