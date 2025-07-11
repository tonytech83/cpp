//
// Created by tonytech on 19.06.2025.
//
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;


int main() {
    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer);

    queue<string> players;

    string name;
    while (iss >> name)
        players.push(name);

    int pass;
    cin >> pass;

    int remainingPasses = pass;
    while (players.size() > 1) {
        remainingPasses--;
        string currPlayer = players.front();
        players.pop();

        if (remainingPasses == 0) {
            cout << "Removed " << currPlayer << endl;
            remainingPasses = pass;
        } else {

            players.push(currPlayer);
        }
    }

    cout << "Last is " << players.front() << endl;

    return 0;
}
