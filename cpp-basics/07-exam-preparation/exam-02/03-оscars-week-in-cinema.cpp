//
// Created by TonyTech on 3.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string film_name, hall_type;
    int ticket_count;
    getline(cin, film_name);
    getline(cin, hall_type);
    cin >> ticket_count;

    double price = 0.0;

    if (film_name == "A Star Is Born") {
        if (hall_type == "normal") {
            price = 7.50;
        } else if (hall_type == "luxury") {
            price = 10.50;
        } else {
            price = 13.50;
        }
    } else if (film_name == "Bohemian Rhapsody") {
        if (hall_type == "normal") {
            price = 7.35;
        } else if (hall_type == "luxury") {
            price = 9.45;
        } else {
            price = 12.75;
        }
    } else if (film_name == "Green Book") {
        if (hall_type == "normal") {
            price = 8.15;
        } else if (hall_type == "luxury") {
            price = 10.25;
        } else {
            price = 13.25;
        }
    } else {
        if (hall_type == "normal") {
            price = 8.75;
        } else if (hall_type == "luxury") {
            price = 11.55;
        } else {
            price = 13.95;
        }
    }

    const double income = price * ticket_count;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << film_name << " -> " << income << " lv." << endl;

    return 0;
}
