//
// Created by tonytech on 30.05.2025.
//
#include <iostream>
#include <list>
using namespace std;

bool is_number(const string &s) {
    for (const char c: s)
        if (!isdigit(c) && c != '-')
            return false;

    return true;
}

void sum(list<int> &s) {
    const int x = s.back();
    s.pop_back();
    const int y = s.back();
    s.pop_back();

    s.push_back(x + y);
}

void subtract(list<int> &s) {
    const int x = s.back();
    s.pop_back();
    const int y = s.back();
    s.pop_back();

    s.push_back(x - y);
}

void concat(list<int> &s) {
    string x = to_string(s.back());
    s.pop_back();
    string y = to_string(s.back());
    s.pop_back();

    s.push_back(stoi(y + x));
}

int main() {
    string input;
    getline(cin, input);

    list<int> commandQueue;

    while (input != "end") {

        if (is_number(input)) {
            commandQueue.push_back(stoi(input));
        } else if (input == "sum") {
            sum(commandQueue);
        } else if (input == "subtract") {
            subtract(commandQueue);
        } else if (input == "concat") {
            concat(commandQueue);
        } else if (input == "discard") {
            commandQueue.pop_back();
        }

        getline(cin, input);
    }

    for (const int i: commandQueue)
        cout << i << endl;

    return 0;
}
