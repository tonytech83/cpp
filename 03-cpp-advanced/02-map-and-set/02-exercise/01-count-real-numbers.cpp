//
// Created by tonytech on 29.6.2025.
//
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

auto main() -> int {
    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer);

    map<double, int> numbers;

    double number;
    while (iss >> number) {
        numbers[number]++;
    }

    for (auto [number, count]: numbers) {
        cout << number << " -> " << count << endl;
    }

    return 0;
}