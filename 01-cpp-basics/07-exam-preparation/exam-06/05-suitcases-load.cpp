//
// Created by TonyTech on 9.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    double trunk_volume;
    cin >> trunk_volume;

    double loaded_volume = 0;
    int loaded_suitcases_count = 0;
    bool is_trunk_full = false;

    string input;
    cin.ignore();
    getline(cin, input);

    while (input != "End") {
        double current_suitcase = stod(input);

        if ((loaded_suitcases_count + 1) % 3 == 0) {
            current_suitcase *= 1.1;
        }

        if (loaded_volume + current_suitcase > trunk_volume) {
            is_trunk_full = true;
            break;
        }

        loaded_volume += current_suitcase;
        loaded_suitcases_count++;

        getline(cin, input);
    }
    if (is_trunk_full) {
        cout << "No more space!" << endl;
    } else {
        cout << "Congratulations! All suitcases are loaded!" << endl;
    }
    cout << "Statistic: " << loaded_suitcases_count << " suitcases loaded." << endl;

    return 0;
}
