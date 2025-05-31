//
// Created by tonytech on 31.05.2025.
//
#include <iostream>
#include <list>
using namespace std;

void fillArray(int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int findAvg(const int arr[], const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

void printFunSequence(const int arr[], const int avg, const int size) {
    list<int> nums;
    for (int i = 0; i < size; i++) {
        if (arr[i] < avg && arr[i] % 2 == 0)
            nums.push_back(arr[i]);
    }
    nums.sort(greater<>());

    if (nums.empty())
        cout << "No" << endl;
    else
        for (const int i : nums)
            cout << i << ' ';

    cout << endl;
}

int main() {
    int arraySize;
    cin >> arraySize;

    if (arraySize <= 0) {
        cout << "No" << endl;
        return 0;
    }

    string buff;
    getline(cin, buff);

    int numbers[arraySize];
    fillArray(numbers, arraySize);
    const int avg = findAvg(numbers, arraySize);

    printFunSequence(numbers, avg, arraySize);

    return 0;
}
