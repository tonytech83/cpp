#include <iostream>

using namespace std;

int main()
{
    const double chickenPrice = 10.35;
    const double fishPrice = 12.40;
    const double veganPrice = 8.15;
    const double delivery = 2.50;

    int chickenCount, fishCount, veganCount;

    cin >> chickenCount >> fishCount >> veganCount;

    double totalBeforeDelivery = chickenCount * chickenPrice + fishCount * fishPrice + veganCount * veganPrice;
    double dessertPrice = totalBeforeDelivery * 0.2;

    double total = totalBeforeDelivery + dessertPrice + delivery;

    cout << total << endl;

    return 0;
}