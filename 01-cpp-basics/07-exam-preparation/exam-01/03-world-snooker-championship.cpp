//
// Created by tonytech on 29-Dec-24.
//

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string competition_stage, ticket_type;
    int ticket_count;
    char picture;

    getline(cin, competition_stage);
    cin >> ticket_type >> ticket_count >> picture;

    double ticket_price = 0.0;

    if (competition_stage == "Quarter final") {
        if (ticket_type == "Standard") {
            ticket_price = 55.50;
        } else if (ticket_type == "Premium") {
            ticket_price = 105.20;
        } else {
            ticket_price = 118.90;
        }
    } else if (competition_stage == "Semi final") {
        if (ticket_type == "Standard") {
            ticket_price = 75.88;
        } else if (ticket_type == "Premium") {
            ticket_price = 125.22;
        } else {
            ticket_price = 300.40;
        }
    } else {
        if (ticket_type == "Standard") {
            ticket_price = 110.10;
        } else if (ticket_type == "Premium") {
            ticket_price = 160.66;
        } else {
            ticket_price = 400;
        }
    }

    double total_price = ticket_price * ticket_count;

    if (total_price > 4000) {
        total_price *= 0.75;
    } else if (total_price > 2500) {
        total_price *= 0.9;
        if (picture == 'Y') {
            total_price += (ticket_count * 40);
        }
    } else {
        if (picture == 'Y') {
            total_price += ticket_count * 40;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << total_price << endl;

    return 0;
}
