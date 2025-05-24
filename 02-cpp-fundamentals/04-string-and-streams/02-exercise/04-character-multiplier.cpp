//
// Created by tonytech on 5/24/25.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;


    int large = str1.length();
    if (str1.length() < str2.length())
        large = str2.length();


    int sum = 0;
    int num1 = 0, num2 = 0;

    for (int i = 0; i < large; i++) {
        if (i < str1.length())
            num1 = str1[i];
        else
            num1 = 1;

        if (i < str2.length())
            num2 = str2[i];
        else
            num2 = 1;

        sum += num1 * num2;
    }

    cout << sum << endl;

    return 0;
}
