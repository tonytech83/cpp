//
// Created by TonyTech on 7.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    double desired_profit, profit = 0.0;
    cin >> desired_profit;

    while (profit < desired_profit) {
        string cocktail_name;
        cin.ignore();
        getline(cin, cocktail_name);
        if (cocktail_name == "Party!") {
            break;
        }
        int cocktail_count;
        cin >> cocktail_count;

        const int cocktail_price = cocktail_name.size();
        const int order_price = cocktail_count * cocktail_price;
        double order_profit = 0.0;
        if (order_price % 2 != 0) {
            order_profit = order_price * 0.75;
        } else {
            order_profit = order_price;
        }

        profit += order_profit;
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    if (profit < desired_profit) {
        cout << "We need " << desired_profit - profit << " leva more." << endl;
    } else {
        cout << "Target acquired." << endl;
    }
    cout << "Club income - " << profit << " leva." << endl;

    return 0;
}
