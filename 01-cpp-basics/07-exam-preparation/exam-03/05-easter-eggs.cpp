//
// Created by tonytech on 05/01/25.
//

#include <iostream>
#include <climits>
#include <string>
using namespace std;

int main() {
    int eggs_count;
    cin >> eggs_count;

    int red_eggs = 0, orange_eggs = 0, blue_eggs = 0, green_eggs = 0;
    int max_eggs = INT_MIN;
    string max_eggs_color;

    for (int i = 0; i < eggs_count; i++) {
        string color;
        cin >> color;

        if (color == "red") {
            red_eggs++;
            if (red_eggs > max_eggs) {
                max_eggs = red_eggs;
                max_eggs_color = "red";
            }
        } else if (color == "orange") {
            orange_eggs++;
            if (orange_eggs > max_eggs) {
                max_eggs = orange_eggs;
                max_eggs_color = "orange";
            }
        } else if (color == "blue") {
            blue_eggs++;
            if (blue_eggs > max_eggs) {
                max_eggs = blue_eggs;
                max_eggs_color = "blue";
            }
        } else {
            green_eggs++;
            if (green_eggs > max_eggs) {
                max_eggs = green_eggs;
                max_eggs_color = "green";
            }
        }
    }

    cout << "Red eggs: " << red_eggs << endl;
    cout << "Orange eggs: " << orange_eggs << endl;
    cout << "Blue eggs: " << blue_eggs << endl;
    cout << "Green eggs: " << green_eggs << endl;
    cout << "Max eggs: " << max_eggs << " -> " << max_eggs_color << endl;


    return 0;
}
