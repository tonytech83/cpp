//
// Created by tonytech on 02.07.2025.
//
#include <iostream>
#include <string>
using namespace std;

auto parse(const char *buffer, int *result) -> bool {
    if (!*buffer)
        return false;

    int iRes = 0;

    while (*buffer) {
        if (*buffer >= '0' && *buffer <= '9') {
            // *buffer currently points to char from '0'...'9'
            iRes = iRes * 10 + *buffer - '0';
        } else
            return false;

        buffer++;
    }


    *result = iRes;
    return true;
}

auto main() -> int {
    string s1, s2;
    cin >> s1 >> s2;

    int iS1, iS2;

    // `.c_str()` returns a pointer to and array that contains a null-terminated sequence of chars
    const bool bS1 = parse(s1.c_str(), &iS1);
    const bool bS2 = parse(s2.c_str(), &iS2);

    if (bS1 && bS2) {
        // both are number
        cout << iS1 + iS2 << endl;
    } else if (bS1) {
        cout << iS1 << endl;
        cout << "[error] " << s2 << endl;
    } else {
        cout << "[error] " << s1 << endl;
        cout << iS2 << endl;
    }

    return 0;
}
