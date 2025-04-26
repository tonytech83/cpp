//
// Created by TonyTech on 8.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    double budget, cost = 0;
    char sex;
    int age;
    string sport_type;
    cin >> budget >> sex >> age >> sport_type;


    if (sex == 'm') {
        if (sport_type == "Gym") {
            cost = 42.0;
        } else if (sport_type == "Boxing") {
            cost = 41.0;
        } else if (sport_type == "Yoga") {
            cost = 45.0;
        } else if (sport_type == "Zumba") {
            cost = 34.0;
        } else if (sport_type == "Dances") {
            cost = 51.0;
        } else {
            cost = 39.0;
        }
    } else {
        if (sport_type == "Gym") {
            cost = 35.0;
        } else if (sport_type == "Boxing") {
            cost = 37.0;
        } else if (sport_type == "Yoga") {
            cost = 42.0;
        } else if (sport_type == "Zumba") {
            cost = 31.0;
        } else if (sport_type == "Dances") {
            cost = 53.0;
        } else {
            cost = 37.0;
        }
    }

    if (age <= 19) {
        cost *= 0.8;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    if (budget >= cost) {
        cout << "You purchased a 1 month pass for " << sport_type << "." << endl;
    } else {
        cout << "You don't have enough money! You need $" << cost - budget << " more." << endl;
    }


    return 0;
}
