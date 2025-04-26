//
// Created by tonytech on 4/26/25.
//

#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;

    int counter = 0;
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 != 0) {
            counter++;
            sum += i;
            cout << i << endl;
        }

        if (counter >= number) break;
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
