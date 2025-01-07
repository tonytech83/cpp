//
// Created by TonyTech on 7.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    string winner_name;
    int winner_points = 0;
    getline(cin, input);

    while (input != "Stop") {
        string player_name = input;
        int player_points = 0;

        for (int i = 0; i < player_name.length(); i++) {
            int number;
            cin >> number;

            if (number == player_name[i]) {
                player_points += 10;
            } else {
                player_points += 2;
            }
        }

        if (player_points >= winner_points) {
            winner_name = player_name;
            winner_points = player_points;
        }

        getline(cin, input);
    }

    cout << "The winner is " << winner_name << " with " << winner_points << " points!" << endl;

    return 0;
}
