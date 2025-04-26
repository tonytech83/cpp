//
// Created by TonyTech on 7.1.2025 г..
//

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int people;
    double entrance_tax, deckchair_price, umbrella_price;
    cin >> people >> entrance_tax >> deckchair_price >> umbrella_price;

    double deckchair_cost = ceil(people * 0.75) * deckchair_price;
    double umbrella_cost = ceil(people * 0.5) * umbrella_price;
    double total_cost = people * entrance_tax + deckchair_cost + umbrella_cost;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << total_cost << " lv." << endl;


    return 0;
}
