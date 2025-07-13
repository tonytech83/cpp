//
// Created by tonytech on 13.7.2025.
//
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

auto main() -> int {
    int citiesCount;
    cin >> citiesCount;
    cin.ignore();

    map<string, double> cities;

    string city;
    double price;
    int quantity;

    while (cin >> city >> price >> quantity) {
        cities[city] += price * quantity * 1.0;

        if (cities.size() == citiesCount)
            break;
    }

    for (const auto &[city, total]: cities) {
        cout << city << ' ' << total << endl;
    }

    return 0;
}
