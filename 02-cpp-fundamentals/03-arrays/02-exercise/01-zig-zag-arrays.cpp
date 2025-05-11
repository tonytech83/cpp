//
// Created by tonytech on 5/11/25.
//
#include <iostream>
using namespace std;

void fillArray(int arr1[], int arr2[], const int size) {
    for (int i = 1; i <= size; i++) {
        int a, b;
        cin >> a >> b;

        if (i % 2 != 0) {
            arr1[i] = a;
            arr2[i] = b;
        } else {
            arr2[i] = a;
            arr1[i] = b;
        }
    }
}

void printArray(int arr[], const int size) {
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    constexpr int maxSize = 99;

    int N;
    cin >> N;

    int arr1[maxSize];
    int arr2[maxSize];
    fillArray(arr1, arr2, N);
    printArray(arr1, N);
    printArray(arr2, N);

    return 0;
}
