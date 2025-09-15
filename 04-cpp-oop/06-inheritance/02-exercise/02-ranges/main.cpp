//
// Created by tonytech on 15.09.2025.
//
#include <iostream>
#include <map>
#include <ranges>
#include <sstream>

#include "Range.h"
using namespace std;


auto main() -> int {
    // Read `Ranges`
    map<int, Range> ranges;
    string line;
    while (getline(cin, line) && line != ".") {
        istringstream iss(line);
        int from, to;
        iss >> from >> to;
        ranges.try_emplace(from, Range{from, to}); // sort our ranges by `from`
    }

    string strNumber;
    while (getline(cin, strNumber) && strNumber != ".") {
        bool in;
        int number = stoi(strNumber);
        auto itStart = ranges.upper_bound(number); // returns iterator of next bigger key in our map<int, Ranges>
        if (itStart == ranges.begin())
            in = false;
        else {
            --itStart;
            in = itStart->second.isInRange(number);
        }

        cout << (in ? "in" : "out") << endl;
    }

    return 0;
}
