//
// Created by TonyTech on 9.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int tournament_days;
    cin >> tournament_days;

    int tournament_result = 0;
    double money_earned =0;



    for (int i = 0; i < tournament_days; i++) {
        string input;
        cin.ignore();
        getline(cin, input);

        double day_result = 0;
        double day_money_earned = 0;

        while (input != "Finish") {
            string result;
            getline(cin, result);

            if (result == "win") {
                day_result++;
                day_money_earned += 20;
            } else {
                day_result--;
            }

            getline(cin, input);
        }

        if (day_result > 0) {
            money_earned += day_money_earned * 1.1;
            tournament_result++;
        } else {
            money_earned += day_money_earned;
            tournament_result--;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    if (tournament_result > 0) {
       cout << "You won the tournament! Total raised money: "<< money_earned * 1.2 << endl;
    } else {
         cout <<    "You lost the tournament! Total raised money: " << money_earned << endl;
    }

    return 0;
}
