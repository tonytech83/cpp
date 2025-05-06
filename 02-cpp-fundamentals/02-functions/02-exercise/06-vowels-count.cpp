//
// Created by tonytech on 5/6/25.
//

#include <iostream>
#include <string>
using namespace std;

int findVowelsCount(const string &word);

bool isVowel(char c);

int main() {
    string word;
    cin >> word;

    cout << findVowelsCount(word) << endl;

    return 0;
}

bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

int findVowelsCount(const string &word) {
    int count = 0;

    for (int idx = 0; idx < word.length(); idx++)
        count += isVowel(word[idx]);

    return count;
}
