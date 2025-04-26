//
// Created by tonytech on 29-Dec-24.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, field;
    getline(cin, name);
    getline(cin, field);

    int player_pints = 301, success_strikes = 0, unsuccess_strikes = 0;


    while (field != "Retire") {
        int points;
        cin >> points;

        int current_points = 0;

        if (field == "Single") {
            current_points = points;
        } else if (field == "Double") {
            current_points = points * 2;
        } else {
            current_points = points * 3;
        }

        if (player_pints - current_points >= 0) {
            player_pints -= current_points;
            success_strikes++;
        } else {
            unsuccess_strikes++;
        }

        if (player_pints == 0) {
            break;
        }

        cin.ignore();
        getline(cin, field);
    }

    if (player_pints == 0) {
        cout << name << " won the leg with " << success_strikes << " shots." << endl;
    } else {
        cout << name << " retired after " << unsuccess_strikes << " unsuccessful shots." << endl;
    }

    return 0;
}
