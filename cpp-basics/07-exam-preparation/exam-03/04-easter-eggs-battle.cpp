//
// Created by tonytech on 04/01/25.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int player_one_eggs, player_two_eggs;
    cin >> player_one_eggs >> player_two_eggs;

    string input;
    cin >> input;

    while (input != "End") {
        if (input == "one") {
            player_two_eggs--;
        } else {
            player_one_eggs--;
        }

        if (player_one_eggs == 0 || player_two_eggs == 0) {
            break;
        }

        cin >> input;
    }

    if (input == "End") {
        cout << "Player one has " << player_one_eggs << " eggs left." << endl;
        cout << "Player two has " << player_two_eggs << " eggs left." << endl;
    } else if (player_one_eggs == 0) {
        cout << "Player one is out of eggs. Player two has " << player_two_eggs << " eggs left." << endl;
    } else {
        cout << "Player two is out of eggs. Player one has " << player_one_eggs << " eggs left." << endl;
    }

    return 0;
}
