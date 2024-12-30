//
// Created by tonytech on 29-Dec-24.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int total_games = 0, wins = 0;
    getline(cin, input);

    while (input != "End of tournaments") {
        string tournament_name = input;
        int games_count;
        cin >> games_count;
        total_games += games_count;

        for (int i = 1; i <= games_count; i++) {
            int home_points, guest_points;
            cin >> home_points >> guest_points;

            if (home_points > guest_points) {
                wins++;
                cout << "Game " << i << " of tournament " << tournament_name << ": win with "
                     << home_points - guest_points << " points." << endl;
            } else {
                cout << "Game " << i << " of tournament " << tournament_name << ": lost with "
                     << guest_points - home_points << " points." << endl;
            }
        }

        cin.ignore();
        getline(cin, input);
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << wins * 100.0 / total_games << "% matches win" << endl;
    cout << (total_games - wins) * 100.0 / total_games << "% matches lost" << endl;

    return 0;
}
