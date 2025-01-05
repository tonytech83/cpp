//
// Created by tonytech on 05/01/25.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int clients;
    cin >> clients;
    cin.ignore();

    double total = 0.0;
    int total_items = 0;


    for (int i = 0; i < clients; i++) {
        string purchase;
        getline(cin, purchase);
        double client_total = 0.0;
        int client_items_count = 0;

        while (purchase != "Finish") {
            if (purchase == "basket") {
                client_total += 1.50;
            } else if (purchase == "wreath") {
                client_total += 3.80;
            } else {
                client_total += 7.0;
            }
            client_items_count++;

            getline(cin, purchase);
        }

        if (client_items_count % 2 == 0) {
            client_total *= 0.8;
        }

        total += client_total;
        total_items += client_items_count;

        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "You purchased " << client_items_count << " items for " << client_total << " leva." << endl;
    }

    cout << "Average bill per client is: "<< total / clients <<" leva." << endl;

    return 0;
}
