//
// Created by tonytech on 29-Dec-24.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string country, apparatus;
    cin >> country >> apparatus;

    double points = 0.0;

    if (country == "Russia") {
        if (apparatus == "ribbon") {
            points = 9.100 + 9.400;
        } else if (apparatus == "hoop") {
            points = 9.300 + 9.800;
        } else {
            points = 9.600 + 9.000;
        }
    } else if (country == "Bulgaria") {
        if (apparatus == "ribbon") {
            points = 9.600 + 9.400;
        } else if (apparatus == "hoop") {
            points = 9.550 + 9.750;
        } else {
            points = 9.500 + 9.400;
        }
    } else {
        if (apparatus == "ribbon") {
            points = 9.200 + 9.500;
        } else if (apparatus == "hoop") {
            points = 9.450 + 9.350;
        } else {
            points = 9.700 + 9.150;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(3);
    cout << "The team of " << country << " get " << points << " on " << apparatus << "." << endl;
    cout.precision(2);
    cout << 100 - points / 20 * 100 << "%" << endl;


    return 0;
}
