//
// Created by TonyTech on 19.12.2024 г..
//

#include <iostream>
#include <limits>
#include <string>

int main() {
    int n;
    std::cin >> n;

    double total_points = 0;
    int presentation_count = 0;

    std::string presentation_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, presentation_name);


    while (presentation_name != "Finish") {
        double presentation_points = 0;
        presentation_count += 1;

        for (int i = 0; i < n; i++) {
            double current_points;
            std::cin >> current_points;

            presentation_points += current_points;
        }
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << presentation_name << " - " << presentation_points / n << "." << std::endl;
        total_points += presentation_points / n;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, presentation_name);
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "Student's final assessment is " << total_points / presentation_count << "." << std::endl;

    return 0;
}
