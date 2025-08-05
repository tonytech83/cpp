//
// Created by tonytech on 11.07.2025.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const string BREAK = ".";

class loc {
    string name;
    pair<string, string> coordinates;

public:
    explicit loc(const string &line) {
        istringstream iss(line);

        // get name
        getline(iss, this->name, ',');

        // get the latitude and longitude as strings
        getline(iss, coordinates.first, ',');
        getline(iss, coordinates.second);
    }

    auto getName() -> string { return this->name; }

    auto getCoordinates() -> pair<string, string> { return this->coordinates; }
};

auto isCoordinates(const string &line) -> bool {
    istringstream iss(line);
    double a, b;
    return iss >> a >> b && iss.eof();
}

auto printLocationByCoordinates(const vector<loc> &l, const string &data) -> string {
    istringstream iss(data);
    string latStr, lonStr;
    iss >> latStr >> lonStr;

    ostringstream oss;
    for (auto loc: l)
        if (latStr == loc.getCoordinates().first && lonStr == loc.getCoordinates().second)
            oss << loc.getName() << ',' << loc.getCoordinates().first << ','
                << loc.getCoordinates().second << endl;

    return oss.str();
}

auto printLocationByName(const vector<loc> &l, const string &data) -> string {
    ostringstream oss;
    for (auto loc: l)
        if (loc.getName() == data)
            oss << loc.getName() << ',' << loc.getCoordinates().first << ','
                << loc.getCoordinates().second << endl;

    return oss.str();
}

auto main() -> int {
    vector<loc> locs;

    string line;
    while (getline(cin, line) && line != BREAK) {
        locs.emplace_back(line);
    }

    string query;
    while (getline(cin, query) && query != BREAK) {
        if (isCoordinates(query))
            cout << printLocationByCoordinates(locs, query);
        else
            cout << printLocationByName(locs, query);
    }
    cout << endl;

    return 0;
}
