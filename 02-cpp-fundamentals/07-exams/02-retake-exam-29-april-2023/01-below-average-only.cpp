//
// Created by tonytech on 31.05.2025.
//
//
// Created by tonytech on 30.05.2025.
//
#include <iostream>
using namespace std;

void fillArray(int arr[], const int array_size) {
    for (int i = 0; i < array_size; i++) {
        cin >> arr[i];
    }
}

int findAvg(const int arr[], const int array_size) {
    int sum = 0;
    for (int i = 0; i < array_size; i++)
        sum += arr[i];

    const int result = sum / array_size;

    return result;
}

int belowAverageSumsMultiplication(const int arr[], const int avg, const int array_size) {
    int evenSum = 0;
    int oddSum = 0;

    for (int i = 0; i < array_size; i++) {
        if (arr[i] <= avg && i % 2 == 0)
            evenSum += arr[i];
        else if (arr[i] <= avg && i % 2 == 1)
            oddSum += arr[i];
    }
    return evenSum * oddSum;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    fillArray(arr, n);
    const int avg = findAvg(arr, n);

    cout << belowAverageSumsMultiplication(arr, avg, n) << endl;

    return 0;
}
