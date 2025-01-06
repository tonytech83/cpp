//
// Created by tonytech on 05/01/25.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string movie_name;
    int days, tickets, percentage;
    double ticket_price;
    getline(cin, movie_name);
    cin >> days >> tickets >> ticket_price >> percentage;


    double profit = days * tickets * ticket_price * (1 - percentage / 100.0);

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The profit from the movie " << movie_name << " is " << profit << " lv." << endl;

    return 0;
}