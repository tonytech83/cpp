//
// Created by tonytech on 12/22/2024.
//

#include <iostream>
#include <string>
using namespace std;

string output(const int STEPS_GOAL, const int current_day_steps) {
    if (current_day_steps >= STEPS_GOAL) {
        return "Goal reached! Good job!\n";
    }
    return to_string(STEPS_GOAL - current_day_steps) + " more steps to reach goal.\n";
}

int main() {
    constexpr int STEPS_GOAL = 10000;
    int current_day_steps = 0;

    bool is_going_home = false;

    while (current_day_steps < STEPS_GOAL && !is_going_home ) {
        string input;
        getline(cin, input);

        if (input == "Going home") {
            getline(cin, input);
            is_going_home = true;
        }

        const int steps = stoi(input);
        current_day_steps += steps;
    }

    cout << output(STEPS_GOAL, current_day_steps) << endl;

    return 0;
}