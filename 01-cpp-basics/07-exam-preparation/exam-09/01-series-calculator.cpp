//
// Created by tonytech on 3/15/25.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string tvSeriesName;
    getline(cin, tvSeriesName);

    int seasonsCount, episodesCount;
    double normalEpisodeTime;

    cin >> seasonsCount >> episodesCount >> normalEpisodeTime;

    const double episodeTime = normalEpisodeTime * 1.2;
    const double totalTime = seasonsCount * (episodesCount * episodeTime + 10);

    cout << "Total time needed to watch the " << tvSeriesName << " series is " << totalTime << " minutes." << endl;

    return 0;
}
