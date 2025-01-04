//
// Created by tonytech on 04/01/25.
//

#include <iostream>
using namespace std;

int main() {
    int eggs_in_store, sold_eggs = 0;
    cin >> eggs_in_store;

    string command;
    cin >> command;

    while (command != "Close") {
        int eggs_count;
        cin >> eggs_count;

        if (command == "Buy") {
            if (eggs_in_store - eggs_count < 0) {
                break;
            }
            sold_eggs += eggs_count;
            eggs_in_store -= eggs_count;
        } else {
            eggs_in_store += eggs_count;
        }

        cin >> command;
    }

    if (command == "Close") {
        cout << "Store is closed!" << endl;
        cout << sold_eggs << " eggs sold." << endl;
    } else {
        cout << "Not enough eggs in store!" << endl;
        cout << "You can buy only " << eggs_in_store << "." << endl;
    }

    return 0;
}
