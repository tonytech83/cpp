#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string footballTeamName, souvenirType;
    int souvenirCount;
    cin >> footballTeamName >> souvenirType >> souvenirCount;

    bool invalidInput = false;
    double souvenirPrice = 0.0;
    if (footballTeamName == "Argentina") {
        if (souvenirType == "flags") {
            souvenirPrice = 3.25;
        } else if (souvenirType == "caps") {
            souvenirPrice = 7.20;
        } else if (souvenirType == "posters") {
            souvenirPrice = 5.10;
        } else if (souvenirType == "stickers") {
            souvenirPrice = 1.25;
        } else {
            cout << "Invalid stock!" << endl;
            invalidInput = true;
        }
    } else if (footballTeamName == "Brazil") {
        if (souvenirType == "flags") {
            souvenirPrice = 4.2;
        } else if (souvenirType == "caps") {
            souvenirPrice = 8.5;
        } else if (souvenirType == "posters") {
            souvenirPrice = 5.35;
        } else if (souvenirType == "stickers") {
            souvenirPrice = 1.20;
        } else {
            cout << "Invalid stock!" << endl;
            invalidInput = true;
        }
    } else if (footballTeamName == "Croatia") {
        if (souvenirType == "flags") {
            souvenirPrice = 2.75;
        } else if (souvenirType == "caps") {
            souvenirPrice = 6.9;
        } else if (souvenirType == "posters") {
            souvenirPrice = 4.95;
        } else if (souvenirType == "stickers") {
            souvenirPrice = 1.1;
        } else {
            cout << "Invalid stock!" << endl;
            invalidInput = true;
        }
    } else if (footballTeamName == "Denmark") {
        if (souvenirType == "flags") {
            souvenirPrice = 3.1;
        } else if (souvenirType == "caps") {
            souvenirPrice = 6.5;
        } else if (souvenirType == "posters") {
            souvenirPrice = 4.8;
        } else if (souvenirType == "stickers") {
            souvenirPrice = 0.9;
        } else {
            cout << "Invalid stock!" << endl;
            invalidInput = true;
        }
    } else {
        cout << "Invalid country!" << endl;
        invalidInput = true;
    }

    cout.setf(ios::fixed);
    cout << setprecision(2);
    if (!invalidInput) {
        const double finalPrice = souvenirCount * souvenirPrice;
        cout << "Pepi bought " << souvenirCount << " " << souvenirType << " of " << footballTeamName << " for " <<
                finalPrice << " lv." << endl;
    }


    return 0;
}
