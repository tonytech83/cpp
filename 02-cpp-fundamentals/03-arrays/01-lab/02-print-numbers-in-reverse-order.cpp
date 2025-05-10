//
// Created by tonytech on 5/10/25.
//
#include <iostream>
using namespace std;

void fillArray(int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printReversedArray(int arr[], const int size) {
    for (int i = size - 1; i >= 0; i--)
        cout << arr[i] << ' ';
}

int main() {
    int N;
    cin >> N;

    int arr[N] = {};
    fillArray(arr, N);
    printReversedArray(arr, N);
    cout << endl;

    return 0;
}
