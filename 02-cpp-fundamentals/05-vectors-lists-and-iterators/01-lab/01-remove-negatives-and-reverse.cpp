//
// Created by tonytech on 5/25/25.
//

#include <iostream>
#include <sstream>
#include <list>
using namespace std;

list<int> readNumbers(const string &str) {
    list<int> numbers;
    istringstream iss(str);

    int number;
    while (iss >> number) {
        numbers.push_back(number);
    }

    return numbers;
}

void removeNegatives(list<int> &numbers) {
    for (auto it = numbers.begin(); it != numbers.end();) {
        if (*it < 0)
            it = numbers.erase(it);
        else
            ++it;
    }
}

void printReversedNumbers(list<int> &numbers) {
    if (numbers.empty()) {
        cout << "empty";
        return;
    }

    numbers.reverse();
    for (const int n: numbers)
        cout << n << ' ';

    cout << endl;
}

int main() {
    string buffer;
    getline(cin, buffer);

    list<int> numbers = readNumbers(buffer);
    removeNegatives(numbers);
    printReversedNumbers(numbers);

    return 0;
}
