//
// Created by tonytech on 5/10/25.
//
#include <iostream>
#include <array>
using namespace std;

void fillArr(array<int, 99> &arr1, array<int, 99> &arr2, const int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < size; i++) {
        cin >> arr2[i];
    }
}

void isIdentical(const array<int, 99> &arr1, const array<int, 99> &arr2, const int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            cout << "Arrays are not identical. Found difference at " << i << " index." << endl;
            return;
        }
        sum += arr1[i];
    }
    cout << "Arrays are identical. Sum: " << sum << endl;
}

int main() {
    constexpr int maxSize = 99;

    int n;
    cin >> n;

    array<int, maxSize> arr1{};
    array<int, maxSize> arr2{};

    fillArr(arr1, arr2, n);
    isIdentical(arr1, arr2, n);


    return 0;
}
