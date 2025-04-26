//
// Created by tonytech on 29-Dec-24.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string player_one_name, player_two_name;
    cin >> player_one_name >> player_two_name;

    int player_one_points = 0, player_two_points = 0;
    bool is_number_wars = false;

    string player_one_input, player_two_input;
    cin >> player_one_input;

    while (player_one_input != "End of game") {
        cin >> player_two_input;

        if (stoi(player_one_input) > stoi(player_two_input)) {
            player_one_points += stoi(player_one_input) - stoi(player_two_input);
        } else if (stoi(player_one_input) < stoi(player_two_input)) {
            player_two_points += stoi(player_two_input) - stoi(player_one_input);
        } else {
            is_number_wars = true;
            break;
        }

        cin.ignore();
        getline(cin, player_one_input);
    }

    if (is_number_wars) {
        cout << "Number wars!" << endl;
        cin >> player_one_input >> player_two_input;
        if (stoi(player_one_input) > stoi(player_two_input)) {
            cout << player_one_name << " is winner with " << player_one_points << " points" << endl;
        } else {
            cout << player_two_name << " is winner with " << player_two_points << " points" << endl;
        }
    } else {
        cout << player_one_name << " has " << player_one_points << " points" << endl;
        cout << player_two_name << " has " << player_two_points << " points" << endl;
    }

    return 0;
}
