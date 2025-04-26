//
// Created by TonyTech on 19.12.2024 г..
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int special = 1111; special <= 9999; special++) {
        int division_count = 0;
        std::string special_to_str = std::to_string(special);

        for (char j : special_to_str) {
            if (j - '0' == 0) {
                break;
            }

            if (n % (j - '0') == 0) {
                division_count++;
            } else {
                break;
            }
        }

        if (division_count == 4) {
            std::cout << special << " ";
        }
    }

    return 0;
}
