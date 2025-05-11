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

void printMagicSums(const array<int, maxSize> &arr, const int size, const int magicSum) {
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] + arr[j] == magicSum)
                cout << arr[i] << " " << arr[j] << endl;
}

int main() {
    int N;
    cin >> N;

    array<int, maxSize> arr{};
    fillArray(arr, N);

    int num;
    cin >> num;

    printMagicSums(arr, N, num);

    return 0;
}
