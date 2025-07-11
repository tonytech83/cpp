//
// Created by tonytech on 10.07.2025.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

auto cleaner(const string &s) -> string {
    // Remove non alpha chars form begging and end of the string and return clean string
    size_t start = 0;
    while (start < s.size() && !isalpha(s[start]))
        start++;

    size_t end = s.size();
    while (end > start && !isalpha(s[end - 1]))
        end--;

    return s.substr(start, end - start);
}

auto findCharInWords(const char &c, const string &s) -> bool {
    const char lowerC = static_cast<char>(tolower(c));
    for (const char ch: s)
        if (tolower(ch) == lowerC)
            return true;

    return false;
}

auto printWords(const set<string> &words) -> void {
    for (const string &word: words)
        cout << word << ' ';
    cout << endl;
}

auto main() -> int {
    string line;
    getline(cin, line);

    istringstream iss(line);

    vector<string> words;
    string word;
    while (iss >> word)
        words.push_back(cleaner(word));

    vector<char> letters;
    char letter;
    while (cin >> letter && letter != '.')
        letters.push_back(letter);

    for (char c: letters) {
        set<string> containLetter;
        for (const string &w: words)
            if (findCharInWords(c, w))
                containLetter.insert(w);

        if (containLetter.empty())
            cout << "---" << endl;
        else
            printWords(containLetter);
    }

    return 0;
}
