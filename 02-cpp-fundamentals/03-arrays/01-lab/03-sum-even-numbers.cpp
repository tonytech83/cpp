//
// Created by tonytech on 5/10/25.
//
#include <iostream>
using namespace std;

void fillArray(int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int sumEvenNumbers(const int arr[], const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }

    return sum;
}

int main() {
    int sizeOfArray;
    cin >> sizeOfArray;

    int intArray[sizeOfArray] = {};
    fillArray(intArray, sizeOfArray);
    cout << sumEvenNumbers(intArray, sizeOfArray) << endl;

    return 0;
}
