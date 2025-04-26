//
// Created by tonytech on 4/26/25.
//

#include <iostream>
using namespace std;

int main() {
    int absoluteValue;
    cin >> absoluteValue;

    while (true) {
        if (absoluteValue % 2 == 0) {
            cout << "The number is: " << abs(absoluteValue) << endl;
            break;
        }
        cout << "Please write an even number." << endl;
        cin >> absoluteValue;
    }


    return 0;
}
