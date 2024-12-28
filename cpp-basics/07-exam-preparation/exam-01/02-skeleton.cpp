//
// Created by tonytech on 28-Dec-24.
//

#include <iostream>
using namespace std;

int main() {
    int olympic_minutes_control, olympic_seconds_control, seconds_per_100_meters;
    double track_length;
    cin >> olympic_minutes_control >> olympic_seconds_control >> track_length >> seconds_per_100_meters;

    const int olympic_control_in_seconds = olympic_minutes_control * 60 + olympic_seconds_control;
    const double time_back = (track_length / 120) * 2.5;
    const double player_time = (track_length / 100) * seconds_per_100_meters - time_back;

    cout.setf(ios::fixed);
    cout.precision(3);

    if (player_time <= olympic_control_in_seconds) {
        cout << "Marin Bangiev won an Olympic quota!\nHis time is " << player_time << "." << "\n";
    } else {
        cout << "No, Marin failed! He was " << abs(olympic_control_in_seconds - player_time) << " second slower.\n";
    }

    return 0;
}
