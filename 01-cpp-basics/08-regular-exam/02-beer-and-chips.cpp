#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    constexpr double BEER_PRICE = 1.20;

    string fanName;
    double budget;
    int beerCount, chipsCount;
    cin >> fanName >> budget >> beerCount >> chipsCount;

    const double beerCost = BEER_PRICE * beerCount;
    const double chipsPrice = beerCost * 0.45;
    const double chipsCost = ceil(chipsPrice * chipsCount);
    const double totalCost = chipsCost + beerCost;

    cout.setf(ios::fixed);
    cout.precision(2);
    if (budget >= totalCost) {
      cout << fanName <<" bought a snack and has "<< budget - totalCost <<" leva left." << endl;
    } else {
      cout << fanName <<" needs "<< totalCost - budget <<" more leva!" << endl;
      }


    return 0;
}
