//
// Created by tonytech on 5/1/25.
//

#include <iostream>
using namespace std;

int main() {
    int start, end;
    cin >> start >> end;

    long int sum = 0;

    for (int i = start; i <= end; i++) {
        cout << i << ' ';
        sum += i;
    }
    cout << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}
