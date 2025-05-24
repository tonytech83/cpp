//
// Created by tonytech on 5/24/25.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string formatString(istream & iss, ostringstream & oss, char seqChar) {
    char ch;
    while (iss >> ch) {
        if (ch != seqChar) {
            oss << ch;
            seqChar = ch;
        }
    }

    return oss.str();
}

int main() {
    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer.substr(1, buffer.length()));
    ostringstream oss;
    oss << buffer[0];
    const char seqChar = buffer[0];

    cout << formatString(iss, oss, seqChar) << endl;

    return 0;
}
