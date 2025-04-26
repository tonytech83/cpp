//
// Created by TonyTech on 7.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int sold_games, hearthstone_count = 0, fornite_count = 0, overwatch_count = 0, others_count = 0;
    cin >> sold_games;
    cin.ignore();

    for (int i = 0; i < sold_games; i++) {
        string game_name;
        getline(cin, game_name);

        if (game_name == "Hearthstone") {
            hearthstone_count++;
        } else if (game_name == "Fornite") {
            fornite_count++;
        } else if (game_name == "Overwatch") {
            overwatch_count++;
        } else {
            others_count++;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Hearthstone - " << hearthstone_count * 100.0 / sold_games << "%" << endl;
    cout << "Fornite - " << fornite_count * 100.0 / sold_games << "%" << endl;
    cout << "Overwatch - " << overwatch_count * 100.0 / sold_games << "%" << endl;
    cout << "Others - " << others_count * 100.0 / sold_games << "%" << endl;

    return 0;
}
