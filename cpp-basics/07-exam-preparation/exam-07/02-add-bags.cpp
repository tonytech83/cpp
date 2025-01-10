//
// Created by TonyTech on 10.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    double luggage_above_20kg,luggage_weight;
    int days_until_travel, luggage_count;
    cin >>luggage_above_20kg>>luggage_weight>>days_until_travel>>luggage_count;

    double cost = 0;

    const double luggage_below_10kg = luggage_above_20kg * 0.2;
    const double luggage_between_10kg_and_20kg = luggage_above_20kg*0.5;

    if (luggage_weight < 10) {
        if (days_until_travel < 7) {
            cost = luggage_below_10kg * 1.4;
        } else if (days_until_travel >= 7 && days_until_travel <= 30) {
            cost = luggage_below_10kg * 1.15;
        } else {
            cost = luggage_below_10kg * 1.1;
        }
    } else if (luggage_weight >= 10 && luggage_weight <= 20) {
        if (days_until_travel < 7) {
            cost = luggage_between_10kg_and_20kg * 1.4;
        } else if (days_until_travel >= 7 && days_until_travel <= 30) {
            cost = luggage_between_10kg_and_20kg * 1.15;
        } else {
            cost = luggage_between_10kg_and_20kg * 1.1;
        }
    } else {
        if (days_until_travel < 7) {
            cost = luggage_above_20kg * 1.4;
        } else if (days_until_travel >= 7 && days_until_travel <= 30) {
            cost = luggage_above_20kg * 1.15;
        } else {
            cost = luggage_above_20kg * 1.1;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The total price of bags is: "<< cost * luggage_count <<" lv. " << endl;

    return 0;
}
