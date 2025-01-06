//
// Created by TonyTech on 6.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string movie_name, food;
    int tickets;
    getline(cin, movie_name);
    cin >> food >> tickets;

    double price;

    if (movie_name == "John Wick") {
        if (food == "Drink") {
            price = 12.00;
        } else if (food == "Popcorn") {
            price = 15.00;
        } else {
            price = 19.00;
        }
    } else if (movie_name == "Star Wars") {
        if (food == "Drink") {
            price = 18.00;
        } else if (food == "Popcorn") {
            price = 25.00;
        } else {
            price = 30.00;
        }

        if (tickets >= 4) {
            price *= 0.7;
        }
    } else {
        if (food == "Drink") {
            price = 9.00;
        } else if (food == "Popcorn") {
            price = 11.00;
        } else {
            price = 14.00;
        }
        if (tickets == 2) {
            price *= 0.85;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Your bill is " << price * tickets << " leva." << endl;

    return 0;
}
