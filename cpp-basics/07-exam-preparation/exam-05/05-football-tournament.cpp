//
// Created by TonyTech on 7.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string football_team;
    int played_games, wins =0, draws = 0, loses = 0;
    getline(cin, football_team);
    cin >> played_games;

    int points= 0;

    for (int i = 0; i < played_games; i++) {
        char result;
        cin >> result;

        if (result == 'W') {
            points+=3;
            wins++;
        } else if (result == 'D') {
            points++;
            draws++;
        } else {
            loses++;
        }
    }

    if (played_games <= 0) {
        cout << football_team <<" hasn't played any games during this season." << endl;
    } else {
        cout <<football_team << " has won "<< points<<" points during this season." << endl;
        cout << "Total stats:" << endl;
        cout << "## W: " << wins << endl;
        cout << "## D: " << draws << endl;
        cout << "## L: " << loses << endl;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Win rate: "<< wins * 100.0 / played_games <<"%" << endl;
    }

    return 0;
}