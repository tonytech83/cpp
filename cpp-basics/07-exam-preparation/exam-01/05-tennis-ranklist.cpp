//
// Created by tonytech on 29-Dec-24.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int tournament_count, points;
    cin >> tournament_count >> points;

    const int initial_points = points;
    int wins = 0;

    for (int i = 0; i < tournament_count; i++) {
        string current_place;
        cin >> current_place;

        if (current_place == "W") {
            wins++;
            points += 2000;
        } else if (current_place == "F") {
            points += 1200;
        } else {
            points += 720;
        }
    }

    cout << "Final points: " << points << "\n";
    cout << "Average points: " << ceil((points - initial_points) / tournament_count) << "\n";
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << wins * 100.0 / tournament_count << "%" << "\n";

    return 0;
}
