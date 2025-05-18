//
// Created by tonytech on 5/18/25.
//
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

void separator(istringstream iss) {
    ostringstream digits, letters, others;

    char chr;
    while (iss >> chr) {
        if (std::isdigit(chr)) {
            digits << chr;
        } else if (std::isalpha(chr)) {
            letters << chr;
        } else {
            others << chr;
        }
    }

    cout << digits.str() << endl << letters.str() << endl << others.str() << endl;
}

int main() {
    string buffer;
    getline(cin, buffer);

    istringstream iss(buffer);
    separator(std::move(iss));

    return 0;
}
