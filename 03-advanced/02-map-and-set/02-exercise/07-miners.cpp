//
// Created by tonytech on 29.6.2025.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

auto main() -> int {
    string resource;
    map<string, int> resources;
    vector<string> appearance;

    while (getline(cin, resource)) {
        if (resource == "stop")
            break;

        int number;
        cin >> number;
        cin.ignore();

        resources[resource] += number;
        if (find(appearance.begin(), appearance.end(), resource) == appearance.end())
            appearance.push_back(resource);
    }

    for (const auto &res: appearance)
        cout << res << " -> " << resources[res] << endl;

    return 0;
}
