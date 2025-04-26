//
// Created by tonytech on 05/01/25.
//

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double episode_time;
    int scenes_number, scenes_duration;
    cin >> episode_time >> scenes_number >> scenes_duration;

    episode_time *= 0.85; // remove preparation time
    episode_time -= scenes_number * scenes_duration;

    if (episode_time >= 0) {
        cout << "You managed to finish the movie on time! You have " << round(episode_time) << " minutes left!" << endl;
    } else {
        cout << "Time is up! To complete the movie you need " << abs(round(episode_time)) << " minutes." << endl;
    }

    return 0;
}