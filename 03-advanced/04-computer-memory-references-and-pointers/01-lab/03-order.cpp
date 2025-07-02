//
// Created by tonytech on 02.07.2025.
//


#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// returns true if a < b
auto companiesCompare(const pair<int *, const char *> &a, const pair<int *, const char *> &b) -> bool {
    return *a.first < *b.first;
}

auto main() -> int {
    char buffer[1000] = {};
    int nextDataIdx = 0;

    vector<pair<int *, const char *>> companies;

    string name;
    while (cin >> name) {
        if (name == "end")
            break;

        int id;
        cin >> id;

        int *prtId = (int *) (buffer + nextDataIdx);
        *prtId = id;
        nextDataIdx += sizeof(id);

        strcpy(buffer + nextDataIdx, name.c_str());

        companies.push_back(pair<int *, const char *>(prtId, buffer + nextDataIdx));

        nextDataIdx += strlen(buffer + nextDataIdx) + 1;
    }

    sort(companies.begin(), companies.end(), companiesCompare);
    for (auto [id, name] : companies) {
        cout << name << ' ' << *id << endl;
    }

    return 0;
}
