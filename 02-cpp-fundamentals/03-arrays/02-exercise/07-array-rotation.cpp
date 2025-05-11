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

void printRotatedArray(array<int, maxSize> &arr, const int size, const int countRotation) {
    for (int i = 0; i < countRotation; i++) {
        for (int j = 0; j < size - 1; j++) {
            const int tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
        }
    }

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    int N;
    cin >> N;

    array<int, maxSize> arr{};
    fillArray(arr, N);

    int number;
    cin >> number;

    printRotatedArray(arr, N, number);

    return 0;
}
