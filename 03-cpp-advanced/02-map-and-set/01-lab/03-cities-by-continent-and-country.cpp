//
// Created by tonytech on 28.6.2025.
//
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

auto main() -> int {
    int count;
    cin >> count;
    cin.ignore();

    map<string, map<string, vector<string>>> word;

    while (count--) {
        string continent, country, city;
        cin >> continent >> country >> city;

        word[continent][country].push_back(city);
    }

    for (const auto &[continent, countries]: word) {
        cout << continent << ':' << endl;
        for (auto [country, cities]: countries) {
            cout << "  " << country << " -> ";

            sort(cities.begin(), cities.end());
            for (size_t i = 0; i < cities.size(); i++) {
                cout << cities[i];
                if (i != cities.size() - 1)
                    cout << ", ";
            }
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}
