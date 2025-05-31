//
// Created by tonytech on 5/31/25.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isNumber(string s) {
    for (const char c: s)
        if (!isdigit(c))
            return false;
    return true;
}

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);

    int currentValue = 0;
    int previousValue = 0;

    string c;
    while (iss >> c) {
        if (isNumber(c)) {
            previousValue = currentValue;
            currentValue = stoi(c);
        } else {
            const int temp = currentValue;
            switch (c[0]) {
                case '+': {
                    currentValue += previousValue;
                    break;
                }
                case '-': {
                    currentValue = previousValue - temp;
                    break;
                }
                case '*': {
                    currentValue *= previousValue;
                    break;
                }
                case '/': {
                    currentValue = previousValue / temp;
                    break;
                }
            }
            previousValue = temp;
        }
    }

    cout << currentValue << ' ' << previousValue << endl;


    return 0;
}
