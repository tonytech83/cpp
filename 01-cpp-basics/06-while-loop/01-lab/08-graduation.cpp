//
// Created by TonyTech on 20.12.2024 г..
//

#include <iostream>
#include <string>

int main() {
    int static CLASSES = 12;
    std::string student_name;
    std::cin >> student_name;

    double total_grade = 0;
    bool cutout = false;


    for (int i = 1; i <= CLASSES; i++) {
        double current_grade;
        std::cin >> current_grade;
        total_grade += current_grade;

        if (current_grade < 4.00) {
            if (cutout) {
                std::cout << student_name << " has been excluded at " << i - 1 << " grade" << std::endl;
                break;
            }
            cutout = true;
        }
    }

    if (!cutout) {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << student_name << " graduated. Average grade: " << total_grade / CLASSES << std::endl;
    }

    return 0;
}
