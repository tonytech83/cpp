//
// Created by tonytech on 07.07.2025.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

auto findLongestString(const string &bestSoFar, const string &current) -> bool {
    return current.length() > bestSoFar.length();
}

auto findShortestString(const string &bestSoFar, const string &current) -> bool {
    return current.length() < bestSoFar.length();
}

auto findEarliestLexicographically(const string &bestSoFar, const string &current) -> bool {
    return current < bestSoFar;
}

auto main() -> int {
    string line;
    getline(cin, line);
    istringstream iss(line);

    vector<string> words;

    string word;
    while (iss >> word)
        words.push_back(word);

    int mode;
    cin >> mode;

    // pointer to function
    bool (*compareFunc)(const string &bestSoFar, const string &current) = nullptr;

    // assigning to pointer a specific function
    switch (mode) {
        case 1:
            compareFunc = findEarliestLexicographically;
            break;
        case 2:
            compareFunc = findShortestString;
            break;
        case 3:
            compareFunc = findLongestString;
            break;
        default:
            break;
    }

    string bestOf = words[0];
    for (int i = 1; i < words.size(); i++) {
        const string &currWord = words[i];
        if (compareFunc(bestOf, currWord))
            bestOf = currWord;
    }

    cout << bestOf << endl;

    return 0;
}
