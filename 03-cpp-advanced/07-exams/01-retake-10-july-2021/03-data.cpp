//
// Created by tonytech on 11.07.2025.
//
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

auto readTable(unordered_map<string, vector<unordered_map<string, string>>> &table, const string &indexField) -> void {
    string line;
    while (getline(cin, line) && line != "[queries]") {
        istringstream iss(line);
        unordered_map<string, string> record;
        string currKey;
        string key;
        string value;
        while (iss >> key >> value) {
            record[key] = value;

            if (key == indexField)
                currKey = value;
        }
        if (!currKey.empty())
            table[currKey].push_back(record);
    }
}

auto printData(unordered_map<string, vector<unordered_map<string, string>>> &table) -> void {
    string query;
    while (getline(cin, query) && query != "end") {
        istringstream iss(query);
        string index, field;
        iss >> index >> field;

        // Search for the index value in the table. If not found, print "[not found]"
        auto it = table.find(index);
        if (it == table.end()) {
            cout << "[not found]" << endl;
            continue;
        }

        // Get a reference to the vector of records `entities` for the found index
        const auto &entities = it->second;
        bool printed = false;

        // `entities` is a vector<unordered_map<string, string>>
        for (const auto &record: entities) {
            // `record` is an unordered_map<string, string>
            auto fieldIt = record.find(field); // fieldIt is an iterator to the requested field (if it exists)
            if (fieldIt != record.end()) {
                if (printed)
                    cout << ' ';
                cout << fieldIt->second;
                printed = true;
            }
        }

        cout << endl;
    }
}

auto main() -> int {
    string indexField;
    cin >> indexField;
    cin.ignore();

    // Example - if index field is age
    //
    // name Joro age 25 place unknown
    // weight 5 name Cat age 25
    //
    // //{
    //  "25" : [
    //      {"name" : "Joro", "age" : "25", "place" : "unknown"},
    //      {"weight" : "5", "name" : "Cat", "age" : "25"}
    //  ]
    //}

    unordered_map<string, vector<unordered_map<string, string>>> table;
    readTable(table, indexField);
    printData(table);

    return 0;
}
