//
// Created by tonytech on 28.6.2025.
//
#include <iostream>
#include <set>
#include <string>

using namespace std;

auto main() -> int {
    int N;
    cin >> N;

    set<string> names;

    while (N--) {
        string name;
        cin >> name;
        names.insert(name);
    }

    for (const auto& name: names)
        cout << name << endl;

    return 0;
}