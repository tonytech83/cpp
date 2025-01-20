#include <iostream>

using namespace std;

int main()
{
    double budget, clothing_price;
    int extra_count;
    cin >> budget >> extra_count >> clothing_price;

    double decor_price = budget * 0.1;

    if (extra_count > 150)
    {
        clothing_price *= 0.9;
    }

    double total = decor_price + extra_count * clothing_price;

    cout.setf(ios::fixed);
    cout.precision(2);

    if (budget >= total)
    {
        cout << "Action!" << "\n";
        cout << "Wingard starts filming with " << budget - total << " leva left." << "\n";
    }
    else
    {
        cout << "Not enough money!" << "\n";
        cout << "Wingard needs " << total - budget << " leva more." << "\n";
    }

    return 0;
}