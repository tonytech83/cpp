//
// Created by tonytech on 5/1/25.
//

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 1; i <= N; i++) {
        int curNumber;
        cin >> curNumber;

        if (curNumber >= max) {
            max = curNumber;
        }

        if (curNumber <= min) {
            min = curNumber;
        }
    }

    cout << min << ' ' << max << endl;

    return 0;
}