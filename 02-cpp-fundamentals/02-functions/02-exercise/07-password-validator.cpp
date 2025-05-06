//
// Created by tonytech on 5/6/25.
//

#include <iostream>
using namespace std;

bool lengthValidation(const string &password);

bool letterAndDigitValidation(const string &password);

bool twoDigitsValidation(const string &password);

int main() {
    string password;
    cin >> password;

    const bool length = lengthValidation(password);
    const bool letterAndDigits = letterAndDigitValidation(password);
    const bool twoDigits = twoDigitsValidation(password);

    if (length && letterAndDigits && twoDigits)
        cout << "Password is valid" << endl;
    else {
        if (!length)
            cout << "Password must be between 6 and 10 characters" << endl;
        if (!letterAndDigits)
            cout << "Password must consist only of letters and digits" << endl;
        if (!twoDigits)
            cout << "Password must have at least 2 digits" << endl;
    }

    return 0;
}

bool lengthValidation(const string &password) {
    if (password.length() >= 6 && password.length() <= 10)
        return true;

    return false;
}

bool letterAndDigitValidation(const string &password) {
    for (int idx = 0; idx < password.length(); idx++)
        if (!(password[idx] >= 48 && password[idx] <= 57 ||
              password[idx] >= 65 && password[idx] <= 90 ||
              password[idx] >= 97 && password[idx] <= 122))
            return false;
    return true;
}

bool twoDigitsValidation(const string &password) {
    int digitCount = 0;
    for (int idx = 0; idx < password.length(); idx++) {
        if (password[idx] >= 48 && password[idx] <= 57)
            digitCount++;
    }

    if (digitCount >= 2)
        return true;

    return false;
}
