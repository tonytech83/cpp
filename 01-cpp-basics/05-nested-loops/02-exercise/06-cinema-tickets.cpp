//
// Created by anton.petrov on 19.12.2024.
//

#include <iostream>
#include <limits>
#include <string>

int main() {
    std::string movie_name;
    std::getline(std::cin, movie_name);

    int student_tickets = 0, standard_tickets = 0, kid_tickets = 0, total_tickets = 0;

    while (movie_name != "Finish") {
        int free_seats;
        std::cin >> free_seats;

        std::string ticket_type;
        std::cin.ignore();
        std::cin >> ticket_type;

        int taken_seats = 0;

        while (ticket_type != "End") {
            total_tickets++;
            taken_seats++;

            if (ticket_type == "student")
                student_tickets++;
            else if (ticket_type == "standard")
                standard_tickets++;
            else
                kid_tickets++;

            if (taken_seats == free_seats) {
                break;
            }
            std::cin >> ticket_type;
        }
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << movie_name << " - " << (taken_seats * 100.0 / free_seats) << "% full." << std::endl;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, movie_name);
    }

    std::cout << "Total tickets: " << total_tickets << std::endl;
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << student_tickets * 1.00 / total_tickets * 100 << "% student tickets." << std::endl;
    std::cout << standard_tickets * 1.00 / total_tickets * 100 << "% standard tickets." << std::endl;
    std::cout << kid_tickets * 1.00 / total_tickets * 100 << "% kids tickets." << std::endl;

    return 0;
}
