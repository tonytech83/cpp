//
// Created by tonytech on 5/6/25.
//
#include <iostream>
#include <string>
using namespace std;

int compareInt();

char compareChar();

string compareString();


int main() {
    string type;
    getline(cin, type);

    if (type == "int")
        cout << compareInt();
    if (type == "char")
        cout << compareChar();
    if (type == "string")
        cout << compareString();

    cout << endl;

    return 0;
}


int compareInt() {
    int a, b;
    cin >> a >> b;

    if (a > b || a == b)
        return a;
    return b;
}

char compareChar() {
    char a, b;
    cin >> a >> b;

    if (a > b || a == b)
        return a;
    return b;
}

string compareString() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    if (a > b || a == b)
        return a;
    return b;
}
