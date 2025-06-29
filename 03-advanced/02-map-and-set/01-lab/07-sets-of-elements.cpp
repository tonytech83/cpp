//
// Created by tonytech on 28.6.2025.
//
#include <iostream>
#include <set>
using namespace std;

auto main() -> int {
    int n, m;
    cin >> n >> m;

    set<int> one, two;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        one.insert(num);
    }

    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        two.insert(num);
    }

    for (const int& num : one) {
        if (two.count(num)) {
            cout << num << ' ';
        }
    }

    cout << endl;

    return 0;
}
