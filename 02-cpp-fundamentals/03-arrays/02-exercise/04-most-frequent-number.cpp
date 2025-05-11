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

void printMostFreqNumber(const array<int, maxSize> &arr, const int size) {
    int maxLength = 0;
    array<int, 10> freq{};

    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    for (int i = 0; i <= 9; i++) {
        if (freq[i] >= maxLength) {
            maxLength = freq[i];
        }
    }

    for (int i = 0; i <= 9; i++) {
        if (freq[i] == maxLength) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    array<int, maxSize> arr{};
    fillArray(arr, N);
    printMostFreqNumber(arr, N);

    return 0;
}
