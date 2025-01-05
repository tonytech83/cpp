//
// Created by tonytech on 05/01/25.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int cake_count;
    cin >> cake_count;

    int current_first_place = 0;
    int winner_points = 0;
    string winner;
    cin.ignore();

    for (int i = 0; i < cake_count; i++) {
        string backer_name;
        getline(cin, backer_name);
        int backer_points = 0;

        string points;
        getline(cin, points);

        while (points != "Stop") {
            backer_points += stoi(points);
            getline(cin, points);
        }

        cout << backer_name << " has " << backer_points << " points." << endl;
        if (backer_points > current_first_place) {
            current_first_place = backer_points;
            cout << backer_name << " is the new number 1!" << endl;
        }

        if (backer_points > winner_points) {
            winner_points = backer_points;
            winner = backer_name;
        }
    }

    cout << winner << " won competition with " << winner_points << " points!" << endl;

    return 0;
}
