//
// Created by tonytech on 5/31/25.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    string input;
    getline(cin, input);
    istringstream iss(input);

    int vowelsCount = 0;
    int nonVowelsCount = 0;
    char ch;

    while (iss >> ch) {
        if (isalpha(ch))
            switch (ch) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'Y':
                    vowelsCount++;
                    break;
                default: nonVowelsCount++;
                    break;
        }
    }

    cout << vowelsCount << ' ' << nonVowelsCount << endl;

    return 0;
}
