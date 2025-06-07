//
// Created by tonytech on 6/1/25.
//
#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

void readTrain(list<string> &train) {
    string input;
    getline(cin, input);
    while (input != "end") {
        train.push_back(input);
        getline(cin, input);
    }
}

void printTrain(const list<string> &train) {
    for (const string &wagon: train) {
        if (wagon == "empty")
            cout << "| ";
        else
            cout << '|' << wagon;
    }
    cout << '|' << endl;
}

void moveWagon(list<string> &train, const string &command) {
    istringstream iss(command);
    char cmd;
    int oldWagonPosition, newWagonPosition;
    iss >> cmd >> oldWagonPosition >> newWagonPosition;

    auto it = train.begin();
    advance(it, oldWagonPosition - 1);
    const string wagon = *it;
    train.erase(it);

    it = train.begin();
    advance(it, newWagonPosition - 1);
    train.insert(it, wagon);
}

void leaveWagon(list<string> &train, const string &command) {
    istringstream iss(command);
    char cmd;
    int position;
    iss >> cmd >> position;

    auto it = train.begin();
    advance(it, position - 1);
    train.erase(it);
}

int main() {
    list<string> train;
    readTrain(train);

    string input;
    getline(cin, input);
    while (input != "E") {
        char command = input[0];

        if (command == 'P') {
            printTrain(train);
        } else if (command == 'M') {
            moveWagon(train, input);
            printTrain(train);
        } else if (command == 'L') {
            leaveWagon(train, input);
            printTrain(train);
        }

        getline(cin, input);
    }

    return 0;
}
