//
// Created by TonyTech on 10.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int joinery_count;
    cin >> joinery_count;
    cin.ignore();

    string joinery_type;
    getline(cin, joinery_type);

    string delivery_type;
    getline(cin, delivery_type);

    if (joinery_count < 10) {
        cout << "Invalid order" << endl;
    } else {
        double price = 0;

        if (joinery_type == "90X130") {
            price = 110.0;
            if (joinery_count > 30 && joinery_count <= 60) {
                price *= 0.95;
            } else if (joinery_count > 60) {
                price *= 0.92;
            }
        } else if (joinery_type == "100X150") {
            price = 140.0;
            if (joinery_count > 40 && joinery_count <= 80) {
                price *= 0.94;
            } else if (joinery_count > 80) {
                price *= 0.9;
            }
        } else if (joinery_type == "130X180") {
            price = 190.0;
            if (joinery_count > 20 && joinery_count <= 50) {
                price *= 0.93;
            } else if (joinery_count > 50) {
                price *= 0.88;
            }
        } else {
            price = 250.0;
            if (joinery_count > 25 && joinery_count <= 50) {
                price *= 0.91;
            } else if (joinery_count > 14) {
                price *= 0.86;
            }
        }

        double cost = joinery_count * price;

        if (delivery_type == "With delivery") {
            cost += 60;
        }

        if (joinery_count >99) {
            cost *= 0.96;
        }

        cout.setf(ios::fixed);
        cout.precision(2);
        cout << cost << " BGN" << endl;
    }

    return 0;
}
