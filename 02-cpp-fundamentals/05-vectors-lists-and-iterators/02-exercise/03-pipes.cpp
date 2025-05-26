//
// Created by tonytech on 5/26/25.
//
#include <iostream>
using namespace std;

void fillArray(int arr[], const int count) {
    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    int checkup[n];
    int installation[n];
    int lifetimes[n];
    fillArray(checkup, n);
    fillArray(installation, n);

    for (int i = 0; i < n; i++) {
        const int damage = installation[i] - checkup[i];
        const int yearsToLive = installation[i] / damage;
        lifetimes[i] = yearsToLive;
    }

    for (const int i: lifetimes)
        cout << i << ' ';

    cout << endl;

    return 0;
}
