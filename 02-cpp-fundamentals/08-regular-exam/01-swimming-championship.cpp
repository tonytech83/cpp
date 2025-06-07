//
// Created by tonytech on 6/1/25.
//
#include <iostream>
using namespace std;

int main() {
    int n, neededPoints, swimmersCount;
    double roomPricePerDay, participationFee;
    cin >> n >> neededPoints >> swimmersCount >> roomPricePerDay >> participationFee;

    double earnedPoints = 0.0;
    double spendMoney = participationFee * swimmersCount;
    double prevEarnedPoints = 0.0;

    for (int day = 1; day <= n; day++) {
        spendMoney += roomPricePerDay * swimmersCount;

        double currEarnedPoints;
        cin >> currEarnedPoints;

        if (day > 1) {
            currEarnedPoints += prevEarnedPoints * 0.05;
        }
        earnedPoints += currEarnedPoints;
        prevEarnedPoints = currEarnedPoints - (day > 1 ? prevEarnedPoints * 0.05 : 0);
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    if (earnedPoints >= neededPoints) {
        cout << "Money left to pay: " << spendMoney * 0.75 << " BGN. " << endl;
        cout << "The championship was successful!" << endl;
    } else {
        cout << "Money left to pay: " << spendMoney * 0.9 << " BGN. " << endl;
        cout << "The championship was not successful." << endl;
    }
    return 0;
}
