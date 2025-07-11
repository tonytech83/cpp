//
// Created by tonytech on 02.07.2025.
//
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;

auto main() -> int {
    // C-array where we will store company names
    char buffer[1000] = {};
    char *nextName = buffer;

    // map<companyId, const char *name>
    map<int, const char *> companies;

    string name;
    while (cin >> name) {
        if (name == "end")
            break;

        int id;
        cin >> id;

        // copy name to buffer with nextName pointer as start point
        strcpy(nextName, name.c_str());

        // add company id as key and pointer to company name as value
        companies[id] = nextName;

        // move the pointer with length of name + 1 because of end of string which is '\0'
        nextName += strlen(nextName) + 1;
    }

    int searchId;
    cin >> searchId;

    auto it = companies.find(searchId);
    if (it != companies.end())
        cout << it->second << ' ' << it->first << endl;
    else
        cout << "[not found]" << endl;

    return 0;
}
