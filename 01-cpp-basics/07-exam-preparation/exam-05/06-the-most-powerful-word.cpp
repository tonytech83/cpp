//
// Created by TonyTech on 7.1.2025 г..
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string word;
    string most_powerful_word;
    double most_powerful_word_points = 0;
    getline(cin, word);

    while (word != "End of words") {
        double word_power = 0.0;

        for (int i = 0; i < word.length(); i++) {
            word_power += word[i];
        }
        vector<char> letter = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'Y', 'U'};
        if (find(letter.begin(), letter.end(), word[0]) != letter.end()) {
            word_power *= word.length();
        } else {
            word_power = floor(word_power / word.length());
        }

        if (word_power > most_powerful_word_points) {
            most_powerful_word = word;
            most_powerful_word_points = word_power;
        }

        getline(cin, word);
    }

    cout << "The most powerful word is " << most_powerful_word << " - " << most_powerful_word_points << endl;

    return 0;
}
