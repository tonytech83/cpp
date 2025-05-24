//
// Created by tonytech on 5/24/25.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool bracketsCorrect(string s) {
    istringstream iss(s);
    int bracketCount = 0;

    char ch;
    while (iss >> ch) {
        switch (ch) {
            case '(':
                bracketCount++;
                break;
            case ')':
                if (bracketCount > 0)
                    bracketCount--;
                else
                    return false;
                break;
        }
    }

    return bracketCount == 0;
}

int main() {
    string expression;
    getline(cin, expression);

    cout << (bracketsCorrect(expression) ? "correct" : "incorrect") << endl;

    return 0;
}
