//
// Created by tonytech on 5/24/25.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer);
    ostringstream oss;

    int sum = 0;

    string element;
    while (iss >> element) {
        if (isdigit(element[0]) || element[0] == '-')
            sum += stoi(element);
        else
            oss << element + ' ';

    }

    cout << sum << endl;
    cout << oss.str() << endl;

    return 0;
}