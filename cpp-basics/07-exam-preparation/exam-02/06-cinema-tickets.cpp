//
// Created by TonyTech on 3.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    int standard_tickets = 0, student_tickets = 0, kid_tickets = 0, total_tickets = 0;

    while (input != "Finish") {
        string movie_name = input;
        int free_seats, movie_tickets = 0;
        cin >> free_seats;

        cin.ignore();
        string ticket_type;
        getline(cin, ticket_type);

        while (ticket_type != "End") {
            total_tickets++;
            movie_tickets++;

            if (ticket_type == "standard") {
                standard_tickets++;
            } else if (ticket_type == "student") {
                student_tickets++;
            } else {
                kid_tickets++;
            }

            if (movie_tickets == free_seats) {
                break;
            }

            getline(cin, ticket_type);
        }

        cout.setf(ios::fixed);
        cout.precision(2);
        cout << movie_name << " - " << movie_tickets * 100.0 / free_seats << "% full." << endl;

        getline(cin, input);
    }

    cout << "Total tickets: "<<total_tickets << endl;
    cout << student_tickets * 100.0/ total_tickets << "% student tickets." << endl;
    cout << standard_tickets * 100.0/ total_tickets << "% standard tickets." << endl;
    cout << kid_tickets * 100.0/ total_tickets << "% kids tickets." << endl;

    return 0;
}
