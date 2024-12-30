//
// Created by tonytech on 29-Dec-24.
//

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int visitors_count;
    cin >> visitors_count;
    cin.ignore();

    int back_count = 0, chest_count = 0, legs_count = 0, abs_count = 0, protein_shake_count = 0, protein_bar_count = 0,
        protein_count = 0;

    for (int i = 0; i < visitors_count; i++) {
        string input;
        getline(cin, input);

        if (input == "Back") {
            back_count++;
        } else if (input == "Chest") {
            chest_count++;
        } else if (input == "Legs") {
            legs_count++;
        } else if (input == "Abs") {
            abs_count++;
        } else if (input == "Protein shake") {
            protein_shake_count++;
            protein_count++;
        } else {
            protein_bar_count++;
            protein_count++;
        }
    }

    cout << back_count << " - back" << endl;
    cout << chest_count << " - chest" << endl;
    cout << legs_count << " - legs" << endl;
    cout << abs_count << " - abs" << endl;
    cout << protein_shake_count << " - protein shake" << endl;
    cout << protein_bar_count << " - protein bar" << endl;

    cout.setf(ios::fixed);
    cout << setprecision(2);
    cout << (visitors_count - protein_count) * 100.0/ visitors_count << "% - work out" << endl;
    cout << protein_count * 100.0 / visitors_count<< "% - protein" << endl;

    return 0;
}
