//
// Created by tonytech on 6/1/25.
//
#include <array>
#include <iostream>
using namespace std;

constexpr int maxSize = 100;

void fillArray(array<int, maxSize> &arr, const int size) {
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

int main() {
    int arraySize;
    cin >> arraySize;
    array<int, maxSize> numbers{};
    fillArray(numbers, arraySize);

    while (arraySize--) {
        for (int i = 0; i < arraySize; i++)
            numbers[i] = numbers[i] + numbers[i + 1];
    }

    cout << numbers[0] << endl;

    return 0;
}