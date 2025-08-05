//
// Created by tonytech on 05.08.2025.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

auto cleanPunctuation(string &word) -> void { word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end()); }

auto foundLetter(const string &word, const char &up, const char &low) -> bool {
    if (word.find(up) != string::npos || word.find(low) != string::npos)
        return true;

    return false;
}

int main() {
    string line;
    getline(cin, line);

    char letter;
    while (cin >> letter, letter != '.') {
        istringstream iss(line);
        const char lowLetter = static_cast<char>(tolower(letter));
        const char upLetter = static_cast<char>(toupper(letter));

        set<string> matchedWords;

        string word;
        while (iss >> word) {
            if (foundLetter(word, lowLetter, upLetter)) {
                cleanPunctuation(word);
                matchedWords.insert(word);
            }
        }

        if (matchedWords.empty())
            cout << "---" << endl;
        else
            for (const auto &w: matchedWords)
                cout << w << ' ';

        cout << endl;
    }

    return 0;
}
