//
// Created by tonytech on 5/10/25.
//
#include <iostream>
#include <array>
using namespace std;

void fillArray(array<int, 99> &arr, const int size) {
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

void subEvenOdd(const array<int, 99> &arr, const int size) {
    int sumEven = 0;
    int sumOdd = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            sumEven += arr[i];
        else
            sumOdd += arr[i];
    }

    cout << sumEven - sumOdd << endl;
}

int main() {
    constexpr int maxSize = 99;

    int num;
    cin >> num;

    array<int, maxSize> arrayOfInts{};
    fillArray(arrayOfInts, num);
    subEvenOdd(arrayOfInts, num);

    return 0;
}
