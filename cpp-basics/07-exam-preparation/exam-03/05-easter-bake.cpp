//
// Created by tonytech on 05/01/25.
//

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int cakes_count;
    cin >> cakes_count;

    int flour_used = 0, sugar_used = 0, max_flour = INT_MIN, max_sugar = INT_MIN;

    for (int i = 0; i < cakes_count; i++) {
        int current_sugar, current_flour;
        cin >> current_sugar >> current_flour;
        if (current_flour > max_flour) {
            max_flour = current_flour;
        }
        if (current_sugar > max_sugar) {
            max_sugar = current_sugar;
        }

        flour_used += current_flour;
        sugar_used += current_sugar;
    }

    const int flour_packages = ceil(flour_used / 750.0);
    const int sugar_packages = ceil(sugar_used / 950.0);

    cout << "Sugar: " << sugar_packages << endl;
    cout << "Flour: " << flour_packages << endl;
    cout << "Max used flour is " << max_flour << " grams, max used sugar is " << max_sugar << " grams." << endl;

    return 0;
}
