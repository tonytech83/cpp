//
// Created by tonytech on 5/24/25.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string text, fnd, repl;
    getline(cin, text);
    getline(cin, fnd);
    getline(cin, repl);



    int idx = text.find(fnd);
    while (idx != string::npos) {
        text.replace(idx, fnd.size(), repl);
        idx = text.find(fnd, idx);
    }

    cout << text << endl;

    return 0;
}
