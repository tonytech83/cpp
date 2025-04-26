//
// Created by TonyTech on 7.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int wall_height, wall_width, percent_without_paint;
    cin >> wall_height >> wall_width >> percent_without_paint;

    double painting_area = wall_height * wall_width * 4 * (1 - percent_without_paint / 100.0);

    cin.ignore();
    string input;
    getline(cin, input);

    while (input != "Tired!") {
        int paint_liters = stoi(input);
        painting_area -= paint_liters;

        if (painting_area <= 0) {
            break;
        }

        getline(cin, input);
    }

    if (painting_area > 0) {
        cout << painting_area << " quadratic m left." << endl;
    } else if (painting_area == 0) {
        cout << "All walls are painted! Great job, Pesho!" << endl;
    } else {
        cout << "All walls are painted and you have " << abs(painting_area) << " l paint left!" << endl;
    }


    return 0;
}
