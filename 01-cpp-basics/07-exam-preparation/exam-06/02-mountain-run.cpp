//
// Created by TonyTech on 8.1.2025 г..
//

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double climb_record_in_sec, distance_to_climb, sec_per_meter;
    cin >> climb_record_in_sec >> distance_to_climb >> sec_per_meter;

    const double delays = floor(distance_to_climb * 1.0 / 50);
    const double current_climb = distance_to_climb * sec_per_meter + delays * 30;

    cout.setf(ios::fixed);
    cout.precision(2);
    if (current_climb < climb_record_in_sec) {
        cout << "Yes! The new record is " << current_climb << " seconds." << endl;
    } else {
        cout << "No! He was " << current_climb - climb_record_in_sec << " seconds slower." << endl;
    }

    return 0;
}
