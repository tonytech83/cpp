//
// Created by TonyTech on 9.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    int bought_food;
    string eaten_food;
    cin >> bought_food >> eaten_food;

    int food_in_gr = bought_food * 1000;

    while (eaten_food != "Adopted") {
        food_in_gr -= stoi(eaten_food);
        cin >> eaten_food;
    }

    if (food_in_gr >= 0) {
        cout << "Food is enough! Leftovers: " << food_in_gr << " grams." << endl;
    } else {
        cout << "Food is not enough. You need " << abs(food_in_gr) << " grams more." << endl;
    }

    return 0;
}
