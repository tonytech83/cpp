//
// Created by tonytech on 9.8.2025.
//
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class ListOfWords {
    vector<string> words;

public:
    explicit ListOfWords(const string &l) {
        istringstream iss(l);

        string word;
        while (iss >> word) {
            words.push_back(word);
        }
    }

    auto getShiftedSentence(const int &shifter) -> string {
        shift(shifter);
        ostringstream oss;

        for (const auto &w: words)
            oss << w << endl;

        return oss.str();
    }

private:
    auto shift(const int &shifter) -> void {
        if (words.empty() || shifter <= 0)
            return;

        for (int i(0); i < shifter; i++) {
            string word = words.back();
            words.pop_back();
            words.insert(words.begin(), word);
        }
    }
};

auto main() -> int {
    string line;
    getline(cin, line);
    int n;
    cin >> n;

    ListOfWords l(line);
    cout << l.getShiftedSentence(n);

    return 0;
}
