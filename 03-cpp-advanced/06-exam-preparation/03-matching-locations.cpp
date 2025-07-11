//
// Created by tonytech on 11.07.2025.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

auto readLocations(vector<string> &l, vector<pair<string, string>> &c) -> void {
    string line;
    while (getline(cin, line) && line != ".") {
        istringstream iss(line);

        // get location name
        string name;
        getline(iss, name, ',');

        // get the latitude and longitude as strings
        string latStr, longStr;
        getline(iss, latStr, ',');
        getline(iss, longStr);

        l.push_back(name);
        c.emplace_back(latStr, longStr);
    }
}

auto isCoordinates(const string &line) -> bool {
    istringstream iss(line);
    double a, b;
    return iss >> a >> b && iss.eof();
}

auto printLocationsByCoordinates(const vector<string> &names, const vector<pair<string, string>> &coordinates,
                                 const string &data) -> void {
    istringstream iss(data);
    string latStr, lonStr;
    iss >> latStr >> lonStr;

    for (int i(0); i < coordinates.size(); i++)
        if (latStr == coordinates[i].first && lonStr == coordinates[i].second)
            cout << names[i] << ',' << coordinates[i].first << ',' << coordinates[i].second << endl;
}

auto printLocationByName(const vector<string> &names, const vector<pair<string, string>> &coordinates,
                         const string &data) -> void {
    for (int i(0); i < names.size(); i++)
        if (names[i] == data)
            cout << names[i] << ',' << coordinates[i].first << ',' << coordinates[i].second << endl;
}

auto main() -> int {
    vector<string> names;
    vector<pair<string, string>> coordinates;

    readLocations(names, coordinates);

    string query;
    while (getline(cin, query) && query != ".") {
        if (isCoordinates(query))
            printLocationsByCoordinates(names, coordinates, query);
        else
            printLocationByName(names, coordinates, query);
    }
    cout << endl;

    return 0;
}
