//
// Created by tonytech on 04/01/25.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string destination, dates_as_str;
    int nights;
    double price = 0.0;
    getline(cin, destination);
    getline(cin, dates_as_str);
    cin >> nights;

    if (destination == "France") {
        if (dates_as_str == "21-23") {
            price = 30.00;
        } else if (dates_as_str == "24-27") {
            price = 35.00;
        } else {
            price = 40.00;
        }
    } else if (destination == "Italy") {
        if (dates_as_str == "21-23") {
            price = 28.00;
        } else if (dates_as_str == "24-27") {
            price = 32.00;
        } else {
            price = 39.00;
        }
    } else {
        if (dates_as_str == "21-23") {
            price = 32.00;
        } else if (dates_as_str == "24-27") {
            price = 37.00;
        } else {
            price = 43.00;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Easter trip to " << destination << " : " << nights * price << " leva." << endl;

    return 0;
}
