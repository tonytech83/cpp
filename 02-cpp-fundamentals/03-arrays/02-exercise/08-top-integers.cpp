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

void printTopIntegers(const array<int, maxSize> &arr, const int size) {
    for (int i = 0; i < size; i++) {
        bool isTopInt = true;

        for (int j = i + 1; j < size; j++)
            if (arr[i] <= arr[j])
                isTopInt = false;

        if (isTopInt)
            cout << arr[i] << ' ';
    }

    cout << endl;
}

int main() {
    int N;
    cin >> N;

    array<int, maxSize> arr{};
    fillArray(arr, N);
    printTopIntegers(arr, N);

    return 0;
}
