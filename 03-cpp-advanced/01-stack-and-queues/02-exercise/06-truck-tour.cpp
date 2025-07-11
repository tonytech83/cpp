//
// Created by tonytech on 26.06.2025.
//
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> petrol, dist;

    for (int i = 0; i < N; i++) {
        int p, d;
        cin >> p >> d;
        petrol.push(p);
        dist.push(d);
    }

    int startPump = 0;
    int petrolTank = 0;
    int passed = 0;

    for (int i = 0; i < 2 * N; ++i) {
        int currP = petrol.front();
        petrol.pop();
        petrol.push(currP);
        int currD = dist.front();
        dist.pop();
        dist.push(currD);

        petrolTank += currP;

        if (petrolTank >= currD) {
            petrolTank -= currD;
            passed++;
            if (passed == N)
                break;
        } else {
            // reset state
            petrolTank = 0;
            passed = 0;
            startPump = i + 1;
        }
    }

    cout << startPump << endl;
    return 0;
}

//////////////////////// Second solution ///////////////////////////
// bool canCompleteCircle(queue<int> dist, queue<int> fuel) {
//     int tankFuel = 0;
//
//     while  (dist.size()) {
//         tankFuel += fuel.front();
//         fuel.pop();
//
//         if (tankFuel > dist.front()) {
//             tankFuel -= dist.front();
//             dist.pop();
//         }
//         else
//             return false;
//     }
//
//     return true;
// }
//
// int main() {
//     int pumpsCount;
//     cin >> pumpsCount;
//     cin.ignore();
//
//     queue<int> petrolAmounts;
//     queue<int> distances;
//
//     for (int i = 0; i < pumpsCount; i++) {
//         int petrol, distance;
//         cin >> petrol >> distance;
//
//         petrolAmounts.push(petrol);
//         distances.push(distance);
//     }
//
//     int idx = 0;
//     for (;idx < pumpsCount; idx++) {
//         if (canCompleteCircle(distances, petrolAmounts))
//             break;
//
//         petrolAmounts.push(petrolAmounts.front());
//         petrolAmounts.pop();
//
//         distances.push(distances.front());
//         distances.pop();
//     }
//
//     cout << idx << endl;
//
//     return 0;
// }