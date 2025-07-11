//
// Created by tonytech on 08.07.2025.
//
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
using namespace std;

constexpr int MAX_SIZE = 100;

auto main () -> int {
    // int * numbers = new int[MAX_SIZE];
    unique_ptr<int[]> numbers(new int[MAX_SIZE]);

    string line;
    getline(cin, line);
    istringstream iss(line);

    int count = 0;
    while (iss >> numbers[count]) {
        count++;
        if (count > MAX_SIZE) {
            cout << "Maximum number exceeded" << endl;
            return 0;
        }
    }

    const int gauss_trick_size = (count /2 + count % 2);
    // int * gauss = new int[gauss_trick_size];
    unique_ptr<int[]> gauss(new int[gauss_trick_size]);

    int gauss_cnt = 0;
    for (; gauss_cnt < count /2; gauss_cnt++)
        gauss[gauss_cnt] = numbers[gauss_cnt] + numbers[count - 1 - gauss_cnt];

    if (count % 2) {
        gauss[gauss_cnt] = numbers[gauss_cnt];
        gauss_cnt++;
    }

    for (int cnt = 0; cnt < gauss_cnt; cnt++)
        cout << gauss[cnt] << ' ' << flush;

    cout << endl;

    return 0;
}