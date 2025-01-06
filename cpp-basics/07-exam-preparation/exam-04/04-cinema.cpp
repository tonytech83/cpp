//
// Created by TonyTech on 6.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    int hall_capacity, people_entered = 0;
    double total = 0.0;
    cin >> hall_capacity;
    cin.ignore();

    string input;
    getline(cin, input);

    while (input != "Movie time!") {
        const int current_people = stoi(input);

        if (people_entered + current_people > hall_capacity) {
            break;
        }

        people_entered += current_people;

        if (current_people % 3 == 0) {
            total += current_people * 5 - 5;
        } else {
            total += current_people * 5;
        }

        getline(cin, input);
    }

    if (input == "Movie time!") {
        cout << "There are " << hall_capacity - people_entered << " seats left in the cinema." << endl;
    } else {
        cout << "The cinema is full." << endl;
    }
    cout << "Cinema income - " << total << " lv." << endl;


    return 0;
}
