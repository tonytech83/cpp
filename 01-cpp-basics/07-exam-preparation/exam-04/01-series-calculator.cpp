//
// Created by tonytech on 05/01/25.
//

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string tv_series_name;
    int season_number, episode_number;
    double episode_duration;
    getline(cin, tv_series_name);
    cin >> season_number >> episode_number >> episode_duration;

    int total_minutes = 0;
    const double episode_duration_without_adds = episode_duration * 1.2;

    total_minutes = floor(season_number * (episode_number * episode_duration_without_adds) + season_number * 10);

    cout << "Total time needed to watch the " << tv_series_name << " series is " << total_minutes << " minutes."
         << endl;

    return 0;
}
