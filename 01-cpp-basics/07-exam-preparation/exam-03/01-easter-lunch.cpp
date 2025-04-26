//
// Created by tonytech on 04/01/25.
//

#include <iostream>
using namespace std;

int main()
{
    int bread_count, dozen_eggs_count, cookies_count;
    cin >> bread_count >> dozen_eggs_count >> cookies_count;

    static double total_cost = bread_count * 3.20 + dozen_eggs_count * 4.35 + cookies_count * 5.4 + 12 *
        dozen_eggs_count * 0.15;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << total_cost << endl;

    return 0;
}
