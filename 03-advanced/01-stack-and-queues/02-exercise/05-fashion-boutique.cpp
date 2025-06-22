//
// Created by tonytech on 6/22/25.
//
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    string buff;
    getline(cin, buff);
    istringstream iss(buff);

    stack<int> clothes;
    int value;
    while (iss >> value)
        clothes.push(value);

    int capacity;
    cin >> capacity;

    int racks = 1;
    int clothesTotal = 0;
    while (!clothes.empty()) {
        int currClotheValue = clothes.top();
        if (clothesTotal + currClotheValue <= capacity) {
            clothesTotal += currClotheValue;
            clothes.pop();
        } else {
            clothesTotal = 0;
            racks++;
        }
    }

    cout << racks << endl;

    return 0;
}
