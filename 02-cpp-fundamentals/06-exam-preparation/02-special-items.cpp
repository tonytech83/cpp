//
// Created by tonytech on 30.05.2025.
//
#include <iostream>
#include <sstream>
#include <list>
#include <string>
using namespace std;

list<char> fillList(const string &str) {
    list<char> lst;
    istringstream iss(str);

    char c;
    while (iss.get(c)) {
        lst.push_back(c);
    }

    return lst;
}

void printClearString(list<char> &lst) {
    list<char> result;

    auto it = lst.begin();
    while (it != lst.end()) {
        switch (*it) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                result.push_back(*it);
                break;
            default:
                if (result.back() != *it) result.push_back(*it);
                break;
        }
        ++it;
    }

    for (const char c : result)
        cout << c;
}

int main() {
    string buffer;
    getline(cin, buffer);

    list<char> chars = fillList(buffer);

    printClearString(chars);

    return 0;
}