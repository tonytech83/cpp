//
// Created by tonytech on 11.07.2025.
//
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


auto printCount(const vector<int> &m, const vector<int> &s, const int value) -> void {
    int counter = 0;

    auto begin = m.begin();

    while (begin != m.end()) {
        auto end = m.begin();
        for (int i = static_cast<int>(begin - m.begin()); i != m.size(); i++) {
            bool foundSeparator = false;
            for (const int sep: s)
                if (m[i] == sep) {
                    end = find(begin, m.end(), m[i]);
                    foundSeparator = true;
                    break;
                }
            if (foundSeparator)
                break;
        }

        if (count(begin, end, value))
            counter++;

        begin = (end == m.end()) ? end : end + 1;
    }

    cout << counter << endl;
}

auto main() -> int {
    vector<int> separators;

    string sepLine;
    getline(cin, sepLine);
    istringstream ss(sepLine);

    int separator;
    while (ss >> separator)
        separators.push_back(separator);

    vector<int> message;

    string messageLine;
    getline(cin, messageLine);
    istringstream iss(messageLine);


    int number;
    while (iss >> number)
        message.push_back(number);

    int searchValue;
    while (cin >> searchValue && searchValue != 0) {
        printCount(message, separators, searchValue);
    }

    return 0;
}
