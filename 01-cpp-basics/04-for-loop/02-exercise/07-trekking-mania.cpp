//
// Created by anton.petrov on 16.12.2024.
//

#include <iostream>

int main() {
    int groups_count;
    std::cin >> groups_count;

    int total_members = 0;
    double musala = 0, momblan = 0, kalimandjaro = 0, k2 = 0, everest = 0;

    for (int i = 0; i < groups_count; i++) {
        int current_group_members;
        std::cin >> current_group_members;

        total_members += current_group_members;

        if (current_group_members <= 5) {
            musala += current_group_members;
        } else if (current_group_members <= 12) {
            momblan += current_group_members;
        } else if (current_group_members <= 25) {
            kalimandjaro += current_group_members;
        } else if (current_group_members <= 40) {
            k2 += current_group_members;
        } else {
            everest += current_group_members;
        }
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << musala / total_members * 100 << "%" << std::endl;
    std::cout << momblan / total_members * 100 << "%" << std::endl;
    std::cout << kalimandjaro / total_members * 100 << "%" << std::endl;
    std::cout << k2 / total_members * 100 << "%" << std::endl;
    std::cout << everest / total_members * 100 << "%" << std::endl;

    return 0;
}
