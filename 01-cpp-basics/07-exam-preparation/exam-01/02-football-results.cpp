//
// Created by tonytech on 28-Dec-24.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int wons = 0, losts = 0, drawns = 0;

    for (int i = 1; i <= 3; i++) {
        string match_result;
        cin >> match_result;

        const int home_goals = stoi(&match_result[0]);
        const int guest_goals = stoi(&match_result[2]);

        if (home_goals > guest_goals) {
            wons++;
        } else if (home_goals < guest_goals) {
            losts++;
        } else {
            drawns++;
        }
    }

    cout << "Team won " << wons << " games.\n";
    cout << "Team lost " << losts << " games.\n";
    cout << "Drawn games: " << drawns << "\n";

    return 0;
}
