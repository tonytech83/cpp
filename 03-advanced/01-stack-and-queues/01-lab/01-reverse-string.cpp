//
// Created by tonytech on 16.06.2025.
//
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    istringstream iss(input);
    stack<char> st;

    for (char c: input)
        st.push(c);

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    cout << endl;

    return 0;
}