//
// Created by anton.petrov on 16.12.2024.
//

#include <iostream>
#include <limits>
#include <string>

int main() {
    std::string actor_name;
    double academy_points;
    int evaluators;

    std::getline(std::cin, actor_name);
    std::cin >> academy_points >> evaluators;

    for (int i = 1; i <= evaluators; i++) {
        std::string jury_name;
        double jury_points;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, jury_name);
        std::cin >> jury_points;

        academy_points += jury_name.size() * jury_points / 2;

        if (academy_points > 1250.5) {
            break;
        }
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);

    if (academy_points > 1250.5) {
        std::cout << "Congratulations, " << actor_name << " got a nominee for leading role with " << academy_points
                  << "!" << std::endl;
    } else {
        std::cout << "Sorry, " << actor_name << " you need " << 1250.5 - academy_points << " more!" << std::endl;
    }

    return 0;
}
