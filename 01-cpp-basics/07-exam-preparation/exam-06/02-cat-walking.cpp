//
// Created by TonyTech on 8.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    int walk_time, walk_count, taken_calories;
    cin >> walk_time >> walk_count >> taken_calories;

    int burned_calories = walk_time * walk_count * 5;

    if (burned_calories * 1.0 / taken_calories >= 0.5) {
        cout << "Yes, the walk for your cat is enough. Burned calories per day: " << burned_calories << "." << endl;
    } else {
        cout << "No, the walk for your cat is not enough. Burned calories per day: " << burned_calories << "." << endl;
    }

    return 0;
}
