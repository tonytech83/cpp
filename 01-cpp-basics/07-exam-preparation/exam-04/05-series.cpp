//
// Created by TonyTech on 6.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    double budget, total_spend = 0.0;
    int tv_serial_number;
    cin >> budget >> tv_serial_number;


    for (int i = 0; i < tv_serial_number; i++) {
        string tv_serial_name;
        double tv_serial_price;
        cin.ignore();
        getline(cin, tv_serial_name);
        cin >> tv_serial_price;

        if (tv_serial_name == "Thrones") {
            tv_serial_price *= 0.5;
        } else if (tv_serial_name == "Lucifer") {
            tv_serial_price *= 0.6;
        } else if (tv_serial_name == "Protector") {
            tv_serial_price *= 0.7;
        } else if (tv_serial_name == "TotalDrama") {
            tv_serial_price *= 0.8;
        } else if (tv_serial_name == "Area") {
             tv_serial_price *= 0.9;
        }

        total_spend += tv_serial_price;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    if (budget >= total_spend) {
        cout << "You bought all the series and left with "<< budget - total_spend<<" lv." << endl;
    } else {
        cout << "You need "<< total_spend - budget<<" lv. more to buy the series!" << endl;
    }



    return 0;
}
