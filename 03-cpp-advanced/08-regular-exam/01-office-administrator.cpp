//
// Created by tonytech on 13.7.2025.
//
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

auto readEmployees(map<string, vector<int>> &e) -> void {
    string line;
    while (getline(cin, line) && line != "END") {
        istringstream iss(line);
        string name;
        int roomNumber;
        iss >> name >> roomNumber;

        e[name].push_back(roomNumber);
    }
}

auto locateEmployee(const map<string, vector<int>> &employees, const string &employee) -> void {
    const auto it = employees.find(employee);
    if (it != employees.end()) {
        cout << employee << ": ";
        vector<int> rooms = it->second;
        sort(rooms.begin(), rooms.end());
        for (const int room: rooms)
            cout << room << ' ';
    } else {
        cout << employee << ": Not found!";
    }

    cout << endl;
}

auto main() -> int {
    map<string, vector<int>> employees;
    readEmployees(employees);

    string employee;
    while (getline(cin, employee) && employee != "END") {
        locateEmployee(employees, employee);
    }

    return 0;
}
