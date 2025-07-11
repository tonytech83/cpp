//
// Created by tonytech on 28.6.2025.
//
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

auto main() -> int {
    string buff;
    getline(cin, buff);
    istringstream iss(buff);

    map<double, unsigned> valuesCount;
    vector<double> values;

    double num;
    while (iss >> num) {
        auto [fst, snd] = valuesCount.insert(pair<double, unsigned>(num, 1));

        if (snd)
            values.push_back(num);
        else
            fst->second++;
    }

    for (const double value : values) {
        cout << value << " - " << valuesCount[value] << " times" << endl;
    }

    return 0;
}
