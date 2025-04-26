//
// Created by tonytech on 04/01/25.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string eggs_size, eggs_paint;
    int eggs_count;

    // Input
    cin >> eggs_size >> eggs_paint >> eggs_count;

    double price = 0;

    if (eggs_size == "Large") {
        if (eggs_paint == "Red") {
            price = eggs_count * 16;
        } else if (eggs_paint == "Green") {
            price = eggs_count * 12;
        } else { // Yellow
            price = eggs_count * 9;
        }
    } else if (eggs_size == "Medium") {
        if (eggs_paint == "Red") {
            price = eggs_count * 13;
        } else if (eggs_paint == "Green") {
            price = eggs_count * 9;
        } else { // Yellow
            price = eggs_count * 7;
        }
    } else {
        if (eggs_paint == "Red") {
            price = eggs_count * 9;
        } else if (eggs_paint == "Green") {
            price = eggs_count * 8;
        } else { // Yellow
            price = eggs_count * 5;
        }
    }

    const double profit = price * 0.65;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << profit << " leva." << endl;

    return 0;
}
