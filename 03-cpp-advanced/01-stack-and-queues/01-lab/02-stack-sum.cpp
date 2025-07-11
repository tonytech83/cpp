//
// Created by tonytech on 16.06.2025.
//
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    istringstream ss(s);

    stack<int> numbers;

    int number;
    while (ss >> number)
        numbers.push(number);

    string command;
    getline(cin, command);

    while (command != "end") {
        istringstream commandStream(command);
        string c;
        int a, b;
        if (command[0] == 'a') {
            commandStream >> c >> a >> b;
            numbers.push(a);
            numbers.push(b);
        } else {
            commandStream >> c >> a;

            if (a <= numbers.size())
                while (a--)
                    numbers.pop();
        }

        getline(cin, command);
    }

    int sum = 0;
    while (!numbers.empty()) {
        sum += numbers.top();
        numbers.pop();
    }

    cout << sum << endl;

    return 0;
}