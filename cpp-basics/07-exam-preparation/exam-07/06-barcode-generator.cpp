//
// Created by TonyTech on 10.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int start, end;
    cin >> start >> end;

    string start_to_str = to_string(start);
    string end_to_str = to_string(end);

    for (int i = to_string(start)[0] - '0'; i <= to_string(end)[0] - '0'; i++) {
        if (i % 2 != 0) {
            for (int j = to_string(start)[1] - '0'; j <= to_string(end)[1] - '0'; j++) {
                if (j % 2 != 0) {
                    for (int k = to_string(start)[2] - '0'; k <= to_string(end)[2] - '0'; k++) {
                        if (k % 2 != 0) {
                            for (int l = to_string(start)[3] - '0'; l <= to_string(end)[3] - '0'; l++) {
                                if (l % 2 != 0) {
                                    cout << i << j << k << l << " ";
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
