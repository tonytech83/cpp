//
// Created by tonytech on 5/25/25.
//
#include <iostream>
#include <list>
#include <sstream>
using namespace std;

list<int> readNumbers(const string &str) {
    list<int> numbers;
    istringstream iss(str);

    int number;
    while (iss >> number)
        numbers.push_back(number);

    return numbers;
}

void add(list<int> &lst, const int digit) {
    lst.push_back(digit);
}

void remove(list<int> &lst, const int digit) {
    lst.remove(digit);
}

void removeAt(list<int> &lst, const int digit) {
    auto it = lst.begin();
    advance(it, digit);
    lst.erase(it);
}

void insert(list<int> &lst, const string& digit) {
    istringstream iss(digit);
    int number, index;
    iss >> number >> index;

    auto it = lst.begin();
    advance(it, index);

    lst.insert(it, number);
}

int main() {
    string buffer;
    getline(cin, buffer);
    list<int> numbers = readNumbers(buffer);

    string input;
    getline(cin, input);

    while (input != "end") {
        istringstream iss(input);
        string command;
        string digit;

        iss >> command;
        getline(iss, digit);

        if (command == "Add") {
            add(numbers, stoi(digit));
        } else if (command == "Remove") {
            remove(numbers, stoi(digit));
        } else if (command == "RemoveAt") {
            removeAt(numbers, stoi(digit));
        } else if (command == "Insert") {
            insert(numbers, digit);
        }

        getline(cin, input);
    }

    for (const int i: numbers)
        cout << i << ' ';

    cout << endl;

    return 0;
}
