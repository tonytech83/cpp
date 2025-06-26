//
// Created by tonytech on 26.06.2025.
//
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

int main() {
    int pumpsCount;
    cin >> pumpsCount;
    cin.ignore();

    queue<int> petrolAmounts;
    queue<int> distances;

    while (pumpsCount--) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        int petrol, distance;
        iss >> petrol >> distance;

        petrolAmounts.push(petrol);
        distances.push(distance);

    }

    int a = 5;


    return 0;
}