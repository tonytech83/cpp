//
// Created by tonytech on 29-Dec-24.
//

#include <iostream>
using namespace std;


string output(const bool failed, const int starting_height, const int jumps_count) {
    if (failed) {
        return "Tihomir failed at " + to_string(starting_height) + "cm after " + to_string(jumps_count) + " jumps.\n";
    }
    return "Tihomir succeeded, he jumped over " + to_string(starting_height - 5) + "cm after " +
        to_string(jumps_count) + " jumps.\n";
};


int main() {
    int desired_height;
    cin >> desired_height;

    int starting_height = desired_height - 30;
    bool failed = false;
    int jumps_count = 0;

    while (starting_height <= desired_height) {
        int attempts_count = 0;

        for (int i = 1; i <= 3; i++) {
            int input;
            cin >> input;
            jumps_count++;
            if (input > starting_height) {
                starting_height += 5;
                break;
            }
            attempts_count++;
        }

        if (attempts_count == 3) {
            failed = true;
            break;
        }
    }

    cout << output(failed, starting_height, jumps_count) << endl;

    return 0;
}
