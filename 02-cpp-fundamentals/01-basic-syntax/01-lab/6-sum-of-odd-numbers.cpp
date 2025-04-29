//
// Created by tonytech on 4/26/25.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    for (int curr = 1; n != 0; curr += 2, n--) {
        cout << curr << endl;
        sum += curr;
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
