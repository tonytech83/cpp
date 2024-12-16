//
// Created by anton.petrov on 16.12.2024.
//

#include <iomanip>
#include <iostream>

int main() {
    int tournaments_count;
    int ranking_points;
    std::cin >> tournaments_count >> ranking_points;

    int tournaments_points = 0;
    int total_wins = 0;

    for (int i = 0; i < tournaments_count; i++) {
        std::string tournament_place;
        std::cin >> tournament_place;

        if (tournament_place == "W") {
            ranking_points += 2000;
            tournaments_points += 2000;
            total_wins++;
        } else if (tournament_place == "F") {
            ranking_points += 1200;
            tournaments_points += 1200;
        } else if (tournament_place == "SF") {
            ranking_points += 720;
            tournaments_points += 720;
        }
    }

    std::cout << "Final points: " << ranking_points << std::endl;
    std::cout << "Average points: " << tournaments_points / tournaments_count << std::endl;

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << static_cast<double>(total_wins) / tournaments_count * 100.00 << "%" << std::endl;

    return 0;
}
