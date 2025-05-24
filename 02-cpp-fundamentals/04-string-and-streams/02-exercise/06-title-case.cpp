//
// Created by tonytech on 5/24/25.
//
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

void capitalizer(string &s) {
    bool mustCapitalize = true;

    for (char &ch: s) {
        if (isalpha(ch)) {
            if (mustCapitalize) {
                ch = toupper(ch);
                mustCapitalize = false;
            }
        } else {
            mustCapitalize = true;
        }
    }
}


int main() {
    string text;
    getline(cin, text);

    capitalizer(text);

    cout << text << endl;

    return 0;
}
