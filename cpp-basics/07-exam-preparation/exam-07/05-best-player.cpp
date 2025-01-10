//
// Created by TonyTech on 10.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    string player_name;
    getline(cin, player_name);

    string best_player;
    bool is_made_hat_trick = false;
    int most_goals = 0;


    while (player_name != "END") {
        int goals;
        cin >> goals;

        if (goals > most_goals) {
            most_goals = goals;
            best_player = player_name;
        }

        if (goals >= 3) {
            is_made_hat_trick = true;
        }
        if (goals >= 10) {
            break;
        }

        cin.ignore();
        getline(cin, player_name);
    }

    cout << best_player << " is the best player!" << endl;
    if (is_made_hat_trick) {
        cout << "He has scored " << most_goals << " goals and made a hat-trick !!!" << endl;
    } else {
        cout << "He has scored " << most_goals << " goals." << endl;
    }

    return 0;
}
