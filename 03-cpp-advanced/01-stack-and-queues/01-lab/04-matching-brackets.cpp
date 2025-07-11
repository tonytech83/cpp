//
// Created by tonytech on 17.06.2025.
//
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string buffer;
    getline(cin, buffer);

    stack<int> openBrackets;

    for (int i = 0; buffer[i] != '\0'; i++) {
        switch (buffer[i]) {
            case '(':
                openBrackets.push(i);
                break;
            case ')':
                cout << buffer.substr(openBrackets.top(), i - openBrackets.top() + 1) << endl;
                openBrackets.pop();
                break;
            default:
                break;
        }
    }

    return 0;
}
