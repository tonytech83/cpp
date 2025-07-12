//
// Created by tonytech on 12.7.2025.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

auto compare(const pair<string, double> &a, const pair<string, double> &b) -> bool {
    return a.second > b.second;
}

auto main() -> int {
    int itemsCount;
    cin >> itemsCount;
    cin.ignore();

    double total = 0.0;
    vector<pair<string, double>> items;

    while (itemsCount--) {
        string item;
        double itemPrice;
        double itemCount;
        cin >> item >> itemPrice >> itemCount;

        total += itemPrice * itemCount;
        items.emplace_back(item, itemPrice * itemCount);

    }

    sort(items.begin(), items.end(), compare);

    cout << "The total sum is: " << total << " lv." << endl;
    for (const auto& [item, price] : items) {
        cout << item << ' ' << price << endl;
    }

    return 0;
}