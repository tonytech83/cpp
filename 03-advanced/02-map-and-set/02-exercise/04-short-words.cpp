//
// Created by tonytech on 29.6.2025.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

auto main() -> int {
    string text;
    getline(cin, text);
    istringstream iss(text);

    set<string> words;

    string word;
    while (iss >> word)
        if (word.size() < 5) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            words.insert(word);
        }


    bool isFirst = true;
    for (const auto& currWord: words) {
        if (!isFirst)
            cout << ", ";
        cout << currWord;
        isFirst = false;
    }
    cout << endl;

    return 0;
}
