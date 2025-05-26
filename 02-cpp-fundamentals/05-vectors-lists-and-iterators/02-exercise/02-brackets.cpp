//
// Created by tonytech on 5/26/25.
//
#include <iostream>
#include <list>
using namespace std;

bool checkExpression(const list<char> &expression) {
    int br0count = 0; // '(' bracket count
    int br1count = 0; // '[' bracket count
    int br2count = 0; // '{' bracket count

    for (const char it : expression) {
        switch (it) {
            case '(':
                br0count++;
                break;
            case ')':
                if (br0count == 0)
                    return false;
                br0count--;
                break;

            case '[':
                if (br0count != 0)
                    return false;
                br1count++;
                break;
            case ']':
                if (br0count != 0 || br1count == 0)
                    return false;
                br1count--;
                break;

            case '{':
                if (br0count != 0 || br1count != 0)
                    return false;
                br2count++;
                break;
            case '}':
                if (br0count != 0 || br1count != 0 || br2count == 0)
                    return false;
                br2count--;
                break;
        }
    }

    return true;
}

int main() {
    string buffer;
    getline(cin, buffer);

    list<char> expression;
    for (char c: buffer)
        expression.push_back(c);

    cout << (checkExpression(expression) ? "valid" : "invalid") << endl;

    return 0;
}
