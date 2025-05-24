//
// Created by tonytech on 5/24/25.
//
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

bool isValidUsername(const string &username) {
    const bool lengthValidation = username.length() >= 3 && username.length() <= 16;
    bool validChars = true;
    for (const char c: username) {
        if (!isalnum(c) && c != '-' && c != '_')
            validChars = false;
    }
    if (validChars && lengthValidation)
        return true;

    return false;
}

bool readUsername(istream &iss, string &username) {
    getline(iss, username, ',');
    if (isspace(username[0]))
        username = username.substr(1, username.length());

    return static_cast<bool>(iss);
}


int main() {
    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer);

    string username;
    while (readUsername(iss, username)) {
        if (isValidUsername(username)) {
            cout << username << endl;
        }
    }

    return 0;
}
