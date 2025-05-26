//
// Created by tonytech on 5/26/25.
//
#include <iostream>
#include <climits>
#include <sstream>
#include <string>
using namespace std;

int convertToMinutes(const string &str) {
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(2));
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer);

    string trainTime;
    getline(cin, trainTime);
    const int trainDepartureTime = convertToMinutes(trainTime);


    int bestTime = INT_MAX;

    string time;
    int idx = 1;
    int bestIdx = 1;
    while (iss >> time) {
        const int currMinutes = convertToMinutes(time);

        int diff = trainDepartureTime - currMinutes;

        if (diff >= 0 && diff < bestTime) {
            bestTime = diff;
            bestIdx = idx;
        }
        idx++;
    }

    cout << bestIdx << endl;

    return 0;
}
