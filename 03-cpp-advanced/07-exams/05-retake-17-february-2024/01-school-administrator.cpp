//
// Created by tonytech on 21.07.2025.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

auto readKids(map<string, vector<int>> &k) -> void {
    string line;
    while (getline(cin, line) && line != "END") {
        istringstream iss(line);
        string name;
        int roomNumber;
        iss >> name >> roomNumber;

        k[name].push_back(roomNumber);
    }
}

auto findKid(const map<string, vector<int>> &k, const string &kid) -> void {
    auto it = k.find(kid);
    if (it != k.end()) {
        cout << kid << ": ";
        vector<int> rooms = it->second;
        sort(rooms.begin(), rooms.end());
        for (const int roomNumber: rooms) {
            cout << roomNumber << ' ';
        }
    } else {
        cout << kid << ": Not found!";
    }

    cout << endl;
}

auto main() -> int {
    map<string, vector<int>> kids;
    readKids(kids);

    string kid;
    while (getline(cin, kid) && kid != "END") {
        findKid(kids, kid);
    }

    return 0;
}
