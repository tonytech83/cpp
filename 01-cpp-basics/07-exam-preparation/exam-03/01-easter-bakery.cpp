//
// Created by tonytech on 04/01/25.
//

#include <iostream>
using namespace std;

int main()
{
    double kilo_flour_price, kilos_flour, kilos_sugar, dozen_eggs, yeast;
    cin >> kilo_flour_price >> kilos_flour >> kilos_sugar >> dozen_eggs >> yeast;

    const double sugar_price = kilo_flour_price * 0.75;
    const double eggs_price = kilo_flour_price * 1.1;
    const double yeast_price = sugar_price * 0.2;

    const double flout_cost = kilos_flour * kilo_flour_price;
    const double sugar_cost = kilos_sugar * sugar_price;
    const double eggs_cost = dozen_eggs * eggs_price;
    const double yeast_cost = yeast * yeast_price;

    const double total_cost = flout_cost + sugar_cost + eggs_cost + yeast_cost;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << total_cost << endl;

    return 0;
}
