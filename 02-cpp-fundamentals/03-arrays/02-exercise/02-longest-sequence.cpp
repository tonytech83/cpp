//
// Created by tonytech on 5/11/25.
//
#include <iostream>
#include <array>
using namespace std;

constexpr int maxSize = 99;

void fillArray(array<int, maxSize> &arr, const int count) {
    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }
}

void printLongestSequence(const array<int, maxSize> &arr, const int count) {
    int currentLength = 1;
    int maxLength = 1;
    int maxItem = arr[0];

    for (int i = 1; i < count; i++) {
        if (arr[i] == arr[i - 1]) {
            currentLength++;
        } else {
            currentLength = 1;
        }

        if (currentLength >= maxLength) {
            maxLength = currentLength;
            maxItem = arr[i];
        }
    }

    for (int i = 0; i < maxLength; i++) {
        cout << maxItem << ' ';
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    array<int, maxSize> arr{};
    fillArray(arr, N);
    printLongestSequence(arr, N);

    return 0;
}
