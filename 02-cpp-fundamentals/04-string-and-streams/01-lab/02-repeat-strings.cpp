//
// Created by tonytech on 5/18/25.
//
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string buffer;
    getline(cin, buffer);

    istringstream inputString(buffer);
    ostringstream outputStream;
    string word;

    while (inputString >> word) {
        for (int i = 0; i < word.length(); i++)
            outputStream << word;
    }

    cout << outputStream.str() << endl;

    return 0;
}
