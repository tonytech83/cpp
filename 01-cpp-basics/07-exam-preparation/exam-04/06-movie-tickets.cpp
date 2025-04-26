//
// Created by TonyTech on 6.1.2025 г..
//

#include <iostream>
using namespace std;

int main() {
    int a1, a2, n;
    cin >> a1 >> a2 >> n;

    for (int i = a1; i <= a2 - 1; i++) {
        for (int j = 1; j <= n - 1; j++) {
            for (int k = 1; k <= n / 2 - 1; k++) {
                if (i % 2  != 0 && (j + k + i)  % 2 != 0) {
                    cout << static_cast<char>(i) << "-" << j << k << i << endl;
                }
            }
        }
    }

    return 0;
}
