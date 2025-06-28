//
// Created by tonytech on 28.6.2025.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

auto main() -> int {
    int count;
    cin >> count;

    vector<string> names;

    while (count--) {
        string name;
        cin >> name;

        if (auto it = find(names.begin(), names.end(), name); it == names.end()) {
            names.push_back(name);
        }
    }

    for (const auto& name: names) {
        cout << name << endl;
    }

    return 0;
}