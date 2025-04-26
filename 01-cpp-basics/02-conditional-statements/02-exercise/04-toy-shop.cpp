#include <iostream>

using namespace std;

int main() {
    const double puzzle_price = 2.60;
    const double doll_price = 3.00;
    const double bear_price = 4.10;
    const double minion_price = 8.20;
    const double truck_price = 2.00;

    double vacation_price;
    int puzzle_count, doll_count, bear_count, minion_count, truck_count;
    cin >> vacation_price >> puzzle_count >> doll_count >> bear_count >> minion_count >> truck_count;

    int toys_count = puzzle_count + doll_count + bear_count + minion_count + truck_count;
    double profit = puzzle_count * puzzle_price + doll_count * doll_price + bear_count * bear_price +
                    minion_count * minion_price + truck_count * truck_price;

    if (toys_count >= 50) {
        profit *= 0.75;
    }

    profit *= 0.9;

    cout.setf(ios::fixed);
    cout.precision(2);

    if (profit >= vacation_price) {
        cout << "Yes! " << profit - vacation_price << " lv left." << "\n";
    } else {
        cout << "Not enough money! " << vacation_price - profit << " lv needed." << "\n";
    }

    return 0;
}
