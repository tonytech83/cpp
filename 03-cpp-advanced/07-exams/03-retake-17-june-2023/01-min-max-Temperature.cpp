//
// Created by tonytech on 12.7.2025.
//
#include <iostream>
#include <map>
using namespace std;

auto main() -> int {
    int citiesCount;
    cin >> citiesCount;

    map<string, pair<double, double>> cities;

    while (cities.size() < citiesCount) {
        string city;
        double minTemperature;
        double maxTemperature;
        cin >> city >> minTemperature >> maxTemperature;

        if (cities.find(city) != cities.end()) {
            cities[city].first = (cities[city].first > minTemperature) ? minTemperature : cities[city].first;
            cities[city].second = (cities[city].second < maxTemperature) ? maxTemperature : cities[city].second;
        } else {
            cities[city].first = minTemperature;
            cities[city].second = maxTemperature;
        }
    }

    for (const auto &[city, temperatures]: cities)
        cout << city << ' ' << temperatures.first << ' ' << temperatures.second << endl;

    return 0;
}
