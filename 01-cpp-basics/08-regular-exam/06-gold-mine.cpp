#include <iostream>

using namespace std;

int main() {
    int locationCount;
    cin >> locationCount;

    for (int i = 0; i < locationCount; i++) {
        double expectedAverageYieldPerDay;
        int daysOnLocation;
        cin >> expectedAverageYieldPerDay >> daysOnLocation;

        double locationYield = 0.0;
        for (int j = 0; j < daysOnLocation; j++) {
            double currentYield;
            cin >> currentYield;

            locationYield += currentYield;
        }

        const double locationAverageYield = locationYield / daysOnLocation;

        cout.setf(ios::fixed);
        cout.precision(2);
        if (locationAverageYield >= expectedAverageYieldPerDay) {
            cout << "Good job! Average gold per day: " << locationAverageYield << "." << endl;
        } else {
            cout << "You need " << expectedAverageYieldPerDay - locationAverageYield << " gold." << endl;
        }
    }
    return 0;
}
