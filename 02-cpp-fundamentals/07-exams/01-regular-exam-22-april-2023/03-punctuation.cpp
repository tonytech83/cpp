//
// Created by tonytech on 31.05.2025.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int main() {
    string essay;
    getline(cin, essay);
    istringstream iss(essay);

    vector<int> sentences;
    int punctuationCounter = 0;
    char ch;
    while (iss.get(ch)) {
        if (ch == '|') {
            if (punctuationCounter >= sentences.size())
                sentences.resize(punctuationCounter + 1);
            sentences[punctuationCounter] += 1;
            punctuationCounter = 0;
        } else if (ispunct(ch) && ch != '|') {
            punctuationCounter++;
        }
    }

    for (int i = 1; i < sentences.size(); i++)
        if (sentences[i])
            cout << i << " symbol sentences: " << sentences[i] << endl;

    return 0;
}
