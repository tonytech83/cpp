//
// Created by tonytech on 5/10/25.
//
#include <iostream>
#include <string>
#include <array>
using namespace std;

void fillArray(array<string, 99> &arr, const int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void reverseArray(array<string, 99> &revArray, const int size) {
    const int itr = size / 2;

    for (int i = 0; i < itr; i++) {
        const string tmp = revArray[i];
        revArray[i] = revArray[size - 1 - i];
        revArray[size - 1 - i] = tmp;
    }
}

void printArray(const array<string, 99> &arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i]<< ' ';
    }
}

int main() {
    constexpr int maxSize = 99;

    int number;
    cin >> number;

    array<string, maxSize> arr;
    fillArray(arr, number);
    reverseArray(arr, number);
    printArray(arr, number);

    return 0;
}
