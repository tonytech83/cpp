#include <iostream>

using namespace std;

int main()
{
    int pencils, markers, cleaningAgent, percentageReduction;

    cin >> pencils >> markers >> cleaningAgent >> percentageReduction;

    const double pencilsPrice = 5.80;
    const double markersPrice = 7.20;
    const double cleaningAgentPrice = 1.20;

    double total = (pencils * pencilsPrice + markers * markersPrice + cleaningAgent * cleaningAgentPrice);
    double totalWithReduction = total - total * percentageReduction / 100;

    cout << totalWithReduction << endl;

    return 0;
}