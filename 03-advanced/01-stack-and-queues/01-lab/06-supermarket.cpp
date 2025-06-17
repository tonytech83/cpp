//
// Created by tonytech on 17.06.2025.
//
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

void processNames(queue<string> &names) {
    while (!names.empty()) {
        cout << names.front() << endl;
        names.pop();
    }
}

int main() {
    string input;
    getline(cin, input);

    queue<string> names;

    while (input != "End") {
        if (input == "Paid")
            processNames(names);
        else
            names.push(input);

        getline(cin, input);
    }
    cout << names.size() << " people remaining." << endl;

    return 0;
}
