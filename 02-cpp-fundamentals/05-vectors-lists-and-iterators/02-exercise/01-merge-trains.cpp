//
// Created by tonytech on 5/26/25.
//
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;


vector<int> trainRead(const string &str) {
    vector<int> result;
    istringstream iss(str);

    int n;
    while (iss >> n)
        result.push_back(n);

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string lineA, lineB;
    getline(cin, lineA);
    getline(cin, lineB);

    vector<int> trainA = trainRead(lineA);
    vector<int> trainB = trainRead(lineB);

    vector<int> mergedTrains;
    vector<int> trainConfiguration;

    while (!trainA.empty() || !trainB.empty()) {
        int railcarA = INT_MAX;
        int railcarB = INT_MAX;

        if (!trainA.empty())
            railcarA = trainA.front();

        if (!trainB.empty())
            railcarB = trainB.front();

        if (railcarA < railcarB) {
            trainConfiguration.push_back(railcarA);
            mergedTrains.push_back('A');
            trainA.erase(trainA.begin());
        } else {
            trainConfiguration.push_back(railcarB);
            mergedTrains.push_back('B');
            trainB.erase(trainB.begin());
        }
    }

    for (const char c : mergedTrains) {
        cout << c;
    }
    cout << endl;

    reverse(trainConfiguration.begin(), trainConfiguration.end());

    for (const int i : trainConfiguration)
        cout << i << ' ';

    cout << endl;

    return 0;
}
