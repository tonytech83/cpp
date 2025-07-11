//
// Created by tonytech on 11.07.2025.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;


auto readTable(vector<vector<string>> &t) -> void {
    string line;
    while (getline(cin, line) && line != "end") {
        istringstream iss(line);

        string tmp;
        vector<string> row;
        while (iss >> tmp) {
            row.push_back(tmp);
        }
        t.push_back(row);
    }
}
auto findMostCommonValue(const vector<vector<string>> &t, const string &name) -> void {
    const auto it = find(t[0].begin(), t[0].end(), name);
    const int idx = static_cast<int>(it - t[0].begin());

    map<string, int> occurrence;
    for (int i(1); i < t.size(); i++)
        occurrence[t[i][idx]]++;


    string commonColumn;
    int bestOccurrence = 0;

    for (const auto &[name, value]: occurrence)
        if (value > bestOccurrence) {
            commonColumn = name;
            bestOccurrence = value;
        }

    cout << commonColumn << ' ' << bestOccurrence << endl;
}

auto main() -> int {
    vector<vector<string>> table;

    readTable(table);

    string colName;
    cin >> colName;

    findMostCommonValue(table, colName);

    return 0;
}
