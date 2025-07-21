//
// Created by tonytech on 21.07.2025.
//
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

constexpr int BAGS = 4;

auto trowFish(stack<string> &bag) -> void {
    if (!bag.empty())
        bag.pop();
}

auto catchFish(vector<stack<string>> &bags) -> void {
    string line;

    while (getline(cin, line) && line != "END") {
        string bagNumber;
        string fishName;
        constexpr char delim = ' ';
        istringstream lineStream(line);
        getline(lineStream, bagNumber, delim);
        getline(lineStream, fishName);

        if (fishName == "THROW")
            trowFish(bags[stoi(bagNumber)]);
        else
            bags[stoi(bagNumber)].push(fishName);
    }
}

auto printBagsContent(const vector<stack<string>> &bags) -> void {
    for (int idx(1); idx < bags.size(); ++idx) {
        stack<string> bag = bags[idx];
        cout << idx << ": ";

        if (bag.empty())
            cout << "<empty>";
        else {
            vector<string> fishNames;
            while (!bag.empty()) {
                fishNames.push_back(bag.top());
                bag.pop();
            }

            bool isFirst = true;
            for (auto it = fishNames.rbegin(); it != fishNames.rend(); ++it) {
                if (isFirst) {
                    isFirst = false;
                    cout << *it;
                } else {
                    cout << ", " << *it;
                }
            }
        }
        cout << endl;
    }
}

auto prepareDistribution(vector<stack<string>> &bags, map<string, int> &res, map<string, int> &pate) -> void {
    string fishName;
    set<string> restaurantFish;

    // Read all restaurant fish into a set
    while (getline(cin, fishName) && fishName != "END")
        restaurantFish.insert(fishName);

    // Go through all bags and distribute
    for (int idx = 1; idx < bags.size(); ++idx) {
        while (!bags[idx].empty()) {
            string currFish = bags[idx].top();
            bags[idx].pop();

            if (restaurantFish.count(currFish))
                res[currFish]++;
            else
                pate[currFish]++;
        }
    }
}


auto printInventories(const map<string, int> &res, const map<string, int> &pate) -> void {
    cout << "Restaurant: ";
    if (res.empty())
        cout << "<nothing>";
    else {
        bool first = true;
        for (const auto &[fishName, quantity]: res) {
            if (first) {
                cout << fishName << ": " << quantity;
                first = false;
            } else {
                cout << ", " << fishName << ": " << quantity;
            }
        }
    }
    cout << endl;
    cout << "Pate: ";
    if (pate.empty())
        cout << "<nothing>";
    else {
        bool first = true;
        for (const auto &[fishName, quantity]: pate) {
            if (first) {
                cout << fishName << ": " << quantity;
                first = false;
            } else {
                cout << ", " << fishName << ": " << quantity;
            }
        }
    }
    cout << endl;
}

auto main() -> int {
    vector<stack<string>> bags(BAGS);
    catchFish(bags);

    printBagsContent(bags);

    map<string, int> restaurant;
    map<string, int> pate;
    prepareDistribution(bags, restaurant, pate);

    printInventories(restaurant, pate);


    return 0;
}
