//
// Created by tonytech on 5/24/25.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string encrypt(istream &iss) {
    ostringstream oss;
    char ch;
    while (iss.get(ch)) {
        oss << static_cast<char>(ch + 3);
    }
    return oss.str();
}

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);

    cout << encrypt(iss) << endl;

    return 0;
}
