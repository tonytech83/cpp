//
// Created by tonytech on 29.6.2025.
//
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

auto main() -> int {
    string line;
    getline(cin, line);
    istringstream ss(line);

    unordered_map<string, int> words;
    vector<string> appearance;
    set<string> seen;

    string word;
    while (ss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words[word]++;
        if (seen.insert(word).second)
            appearance.push_back(word);
    }

    vector<string> occurrences;

    for (const auto& currWord : appearance) {
        if (words[currWord] % 2 != 0)
            occurrences.push_back(currWord);
    }

    bool isFirst = true;
    for (const auto& w : occurrences) {
        if (!isFirst) cout << ", ";
        cout << w;
        isFirst = false;
    }

    return 0;

}
