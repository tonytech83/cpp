//
// Created by tonytech on 5/18/25.
//
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string reverseString(const string &input) {
    ostringstream ostr;

    const int size = input.size() - 1;
    for (int i = size; i >= 0; i--)
        ostr << input[i];

    return ostr.str();
}

int main() {
    string input;
    getline(cin, input);

    while (input != "end") {
        const string reversed = reverseString(input);
        cout << input << " = " << reversed << endl;

        getline(cin, input);
    }
    return 0;
}
