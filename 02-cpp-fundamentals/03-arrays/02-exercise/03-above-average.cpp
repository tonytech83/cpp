//
// Created by tonytech on 5/11/25.
//
#include <iostream>
#include <array>
using namespace std;

constexpr int maxSize = 99;

void fillArray(array<int, maxSize> &arr, const int size) {
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

void printAboveAverage(const array<int, maxSize> &arr, const int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += arr[i];
    }

    const int average = total / size;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= average)
            cout << arr[i] << " ";
    }

    cout << endl;
}


int main() {
    int N;
    cin >> N;

    array<int, maxSize> arr{};
    fillArray(arr, N);
    printAboveAverage(arr, N);

    return 0;
}
