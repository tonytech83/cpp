//
// Created by TonyTech on 6.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string actor_name;
    getline(cin, actor_name);
    double academy_points;
    int evaluators_number;
    bool nominated = false;
    cin >> academy_points >> evaluators_number;

    for (int i = 0; i < evaluators_number; i++) {
        cin.ignore();
        string evaluator_name;
        double current_points;
        getline(cin, evaluator_name);
        cin >> current_points;

        current_points = evaluator_name.size() * current_points / 2;
        academy_points += current_points;

        if (academy_points > 1250.5) {
            nominated = true;
            break;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(1);
    if (nominated) {
        cout << "Congratulations, " << actor_name << " got a nominee for leading role with " << academy_points << "!"
             << endl;
    } else {
        cout << "Sorry, " << actor_name << " you need " << 1250.5 - academy_points << " more!" << endl;
    }

    return 0;
}
