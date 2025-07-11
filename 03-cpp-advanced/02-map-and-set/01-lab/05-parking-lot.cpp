//
// Created by tonytech on 28.6.2025.
//
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

auto main() -> int {
    set<string> plates;
    string line;

    while (getline(cin, line)) {
        if (line == "END")
            break;

        const size_t commaPos = line.find(',');
        string action = line.substr(0, commaPos);
        string plate = line.substr(commaPos + 1);
        plate.erase(0, 1);

        if (action == "IN")
            plates.insert(plate);
        else
            plates.erase(plate);
    }

    if (plates.empty())
        cout << "Parking Lot is Empty" << endl;
    else
        for (const auto &plate: plates)
            cout << plate << endl;

    return 0;
}
