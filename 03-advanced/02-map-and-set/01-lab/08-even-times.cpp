//
// Created by tonytech on 29.6.2025.
//
#include <iostream>
#include <map>
using namespace std;

auto main() -> int {
    int count;
    cin >> count;

    map<int, int> numbers;

    while (count--) {
        int number;
        cin >> number;

        numbers[number]++;
    }

    for (auto [number, count]: numbers) {
        if (count % 2 == 0) {
            cout << number << endl;
        }
    }

    return 0;
}
