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

void printCartesianProduct(const array<int, maxSize> &arr, const int size) {
    const int cartesianSize = size * size;
    int cartesianArray[cartesianSize];


    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            const int idx = i * size + j;
            cartesianArray[idx] = arr[i] * arr[j];
        }

    for (int i = 0; i < cartesianSize; i++)
        cout << cartesianArray[i] << ' ';
}

int main() {
    int N;
    cin >> N;

    array<int, maxSize> arr{};
    fillArray(arr, N);
    printCartesianProduct(arr, N);

    return 0;
}
