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
    while (iss >> number)
        numbers.push_back(number);

    return numbers;
}

list<int> mergeLists(const list<int> &n1, const list<int> &n2) {
    list<int> result;

    auto iter1 = n1.begin();
    auto iter2 = n2.begin();

    while (iter1 != n1.end() || iter2 != n2.end()) {
        if (iter1 != n1.end()) {
            result.push_back(*iter1);
            ++iter1;
        }
        if (iter2 != n2.end()) {
            result.push_back(*iter2);
            ++iter2;
        }
    }

    return result;
}

int main() {
    string buffer1, buffer2;
    getline(cin, buffer1);
    getline(cin, buffer2);

    const list<int> numbers1 = readNumbers(buffer1);
    const list<int> numbers2 = readNumbers(buffer2);
    const list<int> merged = mergeLists(numbers1, numbers2);

    for (const int i: merged)
        cout << i << ' ';

    cout << endl;

    return 0;
}
