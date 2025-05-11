//
// Created by tonytech on 5/11/25.
//
#include <iostream>
#include <array>
#include <climits>
using namespace std;

constexpr int maxSize = 99;

void fillArray(array<int, maxSize> &arr, const int size) {
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

void printClosestNumberByValue(const array<int, maxSize> &arr, const int size) {
    int minDiff = INT_MAX;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(arr[i] - arr[j]) < minDiff) {
                minDiff = abs(arr[i] - arr[j]);
            }
        }
    }

    if (size == 1)
        minDiff = 0;

    cout << minDiff << endl;
}

int main() {
    int N;
    cin >> N;

    array<int, maxSize> arr{};
    fillArray(arr, N);
    printClosestNumberByValue(arr, N);

    return 0;
}
