//
// Created by TonyTech on 13.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string contract_term, contract_type, is_mobile;
    int mounts;
    cin >> contract_term >> contract_type >> is_mobile >> mounts;

    double tax = 0.0;

    if (contract_term == "one") {
        if (contract_type == "Small") {
            tax = 9.98;
        } else if (contract_type == "Middle") {
            tax = 18.99;
        } else if (contract_type == "Large") {
            tax = 25.98;
        } else {
            tax = 35.99;
        }
    } else {
        if (contract_type == "Small") {
            tax = 8.58;
        } else if (contract_type == "Middle") {
            tax = 17.09;
        } else if (contract_type == "Large") {
            tax = 23.59;
        } else {
            tax = 31.79;
        }
    }

    if (is_mobile == "yes") {
        if (tax <= 10) {
            tax += 5.5;
        } else if (tax <= 30) {
            tax += 4.35;
        } else {
            tax += 3.85;
        }
    }

    double total = tax * mounts;
    if (contract_term == "two") {
        total *= 0.9625;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << total << " lv." << endl;

    return 0;
}
