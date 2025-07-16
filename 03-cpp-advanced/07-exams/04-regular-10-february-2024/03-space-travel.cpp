//
// Created by tonytech on 16.07.2025.
//
#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


auto scanSolarSystem(vector<string> &ss) -> void {
    string body;
    while (getline(cin, body) && body != "END")
        ss.push_back(body);
}

auto readTravelTimes(vector<vector<int>> &tM, const int size) -> void {
    for (int r(0); r < size; ++r)
        for (int c(0); c < size; ++c)
            cin >> tM[r][c];
}

auto printShortestRoutes(const vector<string> &sS, const vector<vector<int>> &tM) -> void {
    int shortPath = INT_MAX;
    vector<pair<int, int>> coordinates;

    for (int r(0); r < tM.size(); ++r)
        for (int c(0); c < tM[r].size(); ++c)
            if (tM[r][c] <= shortPath && tM[r][c] > 0) {
                if (tM[r][c] < shortPath) {
                    coordinates.clear();
                    shortPath = tM[r][c];
                }
                coordinates.emplace_back(r, c);
            }

    for (auto [from, to]: coordinates)
        cout << shortPath << ": " << sS[from] << " -> " << sS[to] << endl;
}

auto printLongestRoutes(const vector<string> &sS, const vector<vector<int>> &tM) -> void {
    int longestPath = 0;
    vector<pair<int, int>> coordinates;

    for (int r(0); r < tM.size(); ++r)
        for (int c(0); c < tM[r].size(); ++c)
            if (tM[r][c] >= longestPath) {
                if (tM[r][c] > longestPath) {
                    coordinates.clear();
                    longestPath = tM[r][c];
                }
                coordinates.emplace_back(r, c);
            }

    for (auto [from, to]: coordinates)
        cout << longestPath << ": " << sS[from] << " -> " << sS[to] << endl;
}

auto printPathLength(const string &path, const vector<string> &sS, const vector<vector<int>> &tM, int &total) -> void {
    int pathSum = 0;
    istringstream iss(path);

    string prevObject;
    vector<string> objects;
    string object;
    while (iss >> object) {
        if (prevObject.empty())
            prevObject = object;
        else {

            auto itF = find(sS.begin(), sS.end(), prevObject);
            auto itT = find(sS.begin(), sS.end(), object);

            pathSum += tM[itF - sS.begin()][itT - sS.begin()];
            prevObject = object;
        }
    }
    total += pathSum;
    cout << pathSum << endl;
}


auto main() -> int {
    vector<string> solarSystem;
    scanSolarSystem(solarSystem);

    const int solarSize = static_cast<int>(solarSystem.size());
    vector travelMatrix(solarSize, vector<int>(solarSize));
    readTravelTimes(travelMatrix, solarSize);

    printShortestRoutes(solarSystem, travelMatrix);
    printLongestRoutes(solarSystem, travelMatrix);

    int totalLength = 0;
    string path;
    cin.ignore();
    while (getline(cin, path) && path != "END") {
        printPathLength(path, solarSystem, travelMatrix, totalLength);
    }
    cout << totalLength << endl;

    return 0;
}
