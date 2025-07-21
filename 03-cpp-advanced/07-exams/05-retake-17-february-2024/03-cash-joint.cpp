//
// Created by tonytech on 21.07.2025.
//
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

auto dataInit(map<string, double> &d, vector<string> &t) -> void {
    string line;
    while (getline(cin, line) && line != "END") {
        istringstream iss(line);
        string ticker;
        double amount;
        iss >> ticker >> amount;

        t.emplace_back(ticker);
        d[ticker] += amount;
    }
}


auto printAccounts(map<string, double> &d, const vector<string> &t) -> void {
    for (const string &ticker: t)
        cout << fixed << setprecision(2) << ticker << ": " << d[ticker] << endl;
}

auto main() -> int {
    map<string, double> data;
    vector<string> tickers;
    dataInit(data, tickers);

    string commandLine;
    while (getline(cin, commandLine) && commandLine != "END") {
        istringstream iss(commandLine);
        char command;
        string firstTicker;
        double amount;
        string secondTicker;
        double exchange;
        iss >> command;

        switch (command) {
            case '+':
                iss >> firstTicker >> amount;
                data[firstTicker] += amount;
                break;
            case '-':
                iss >> firstTicker >> amount;
                data[firstTicker] -= amount;
                break;
            case 'X':
                iss >> firstTicker >> amount >> secondTicker >> exchange;
                data[firstTicker] -= amount;
                data[secondTicker] += amount * exchange;
                break;
            case 'P':
                printAccounts(data, tickers);
                break;
            default:
                break;
        }
    }

    return 0;
}
