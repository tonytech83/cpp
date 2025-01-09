//
// Created by TonyTech on 9.1.2025 г..
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int days;
    double food, food_eaten = 0, dog_food_eaten = 0, cat_food_eaten = 0, biscuits_eaten = 0;
    cin >> days >> food;

    for (int day = 1; day <= days; day++) {
        int dog_food_for_day, cat_food_for_day;
        cin >> dog_food_for_day >> cat_food_for_day;

        dog_food_eaten += dog_food_for_day;
        cat_food_eaten += cat_food_for_day;
        food_eaten += (dog_food_for_day + cat_food_for_day);

        if (day % 3 == 0) {
            biscuits_eaten += (dog_food_for_day + cat_food_for_day) * 0.1;
        }
    }

    cout << "Total eaten biscuits: " << round(biscuits_eaten) << "gr." << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << food_eaten / food * 100 << "% of the food has been eaten." << endl;
    cout << dog_food_eaten / food_eaten * 100 << "% eaten from the dog." << endl;
    cout << cat_food_eaten / food_eaten * 100 << "% eaten from the cat." << endl;

    return 0;
}
