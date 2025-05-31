//
// Created by tonytech on 31.05.2025.
//
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string message;
    getline(cin, message);
    istringstream iss(message);

    int sum = 0;
    char ch;
    while (iss >> ch)
        if (isdigit(ch))
            sum += ch - '0';

    if (sum >= 65 && sum <= 90 || sum >= 97 && sum <= 122)
        cout << static_cast<char>(sum) << endl;
    else
        cout << sum << endl;

    return 0;
}
