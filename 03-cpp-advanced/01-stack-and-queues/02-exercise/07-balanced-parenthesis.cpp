//
// Created by tonytech on 27.06.2025.
//
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &input) {
    stack<char> parenthesis;

    for (char ch: input) {
        if (ch == '(' || ch == '[' || ch == '{') {
            parenthesis.push(ch);
        } else {
            if (parenthesis.empty())
                return false;

            const char top = parenthesis.top();
            parenthesis.pop();

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    string buff;
    getline(cin, buff);
    istringstream iss(buff);

    cout << (isBalanced(buff) ? "YES" : "NO") << endl;

    return 0;
}
