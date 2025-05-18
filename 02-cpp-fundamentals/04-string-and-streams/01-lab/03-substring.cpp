//
// Created by tonytech on 5/18/25.
//
#include <iostream>
#include <string>
using namespace std;

string removeFirstFromSecond(const string &a, string &b) {
    int idx = b.find(a);
    while (idx != string::npos) {
        b.erase(idx, a.length());
        idx = b.find(a);
    }
    return b;
}

int main() {
    string firstStr, secondStr;
    getline(cin, firstStr);
    getline(cin, secondStr);

    const string result = removeFirstFromSecond(firstStr, secondStr);
    cout << result << endl;

    return 0;
}
