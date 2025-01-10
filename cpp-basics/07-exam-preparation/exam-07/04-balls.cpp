//
// Created by TonyTech on 10.1.2025 г..
//

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int balls_count;
    cin >> balls_count;

    int total_points = 0, red_balls = 0, orange_balls = 0, yellow_balls = 0, white_balls = 0, other_balls = 0,
        black_balls = 0;

    for (int i = 1; i <= balls_count; i++) {
        string ball_color;
        cin >> ball_color;

        if (ball_color == "red") {
            total_points += 5;
            red_balls++;
        } else if (ball_color == "orange") {
            total_points += 10;
            orange_balls++;
        } else if (ball_color == "yellow") {
            total_points += 15;
            yellow_balls++;
        } else if (ball_color == "white") {
            total_points += 20;
            white_balls++;
        } else if (ball_color == "black") {
            total_points = floor(total_points / 2.0);
            black_balls++;
        } else {
            other_balls++;
        }
    }

    cout << "Total points: " << total_points << endl;
    cout << "Red balls: " << red_balls << endl;
    cout << "Orange balls: " << orange_balls << endl;
    cout << "Yellow balls: " << yellow_balls << endl;
    cout << "White balls: " << white_balls << endl;
    cout << "Other colors picked: " << other_balls << endl;
    cout << "Divides from black balls: " << black_balls << endl;

    return 0;
}
