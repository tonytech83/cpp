//
// Created by tonytech on 05.08.2025.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

class Letters {
    set<string> words;

public:
    explicit Letters(const string &line) {
        istringstream iss(line);

        string word;
        while (iss >> word) {
            cleanPunctuation(word);
            this->words.insert(word);
        }
    }

private:
    static auto cleanPunctuation(string &word) -> void {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
    }

    static auto foundLetter(const string &word, const char &up, const char &low) -> bool {
        if (word.find(up) != string::npos || word.find(low) != string::npos)
            return true;

        return false;
    }

public:
    [[nodiscard]] auto process(const char &letter) const -> string {
        const char lowLetter = static_cast<char>(tolower(letter));
        const char upLetter = static_cast<char>(toupper(letter));
        ostringstream oss;

        if (this->words.empty())
            oss << "---" << endl;
        else
            for (const auto &w: this->words)
                if (foundLetter(w, lowLetter, upLetter))
                    oss << w << ' ';

        return oss.str();
    }
};

int main() {
    string line;
    getline(cin, line);

    const Letters l(line);

    char letter;
    while (cin >> letter, letter != '.')
        cout << l.process(letter) << endl;

    return 0;
}
