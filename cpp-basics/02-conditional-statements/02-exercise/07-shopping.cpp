#include <iostream>

using namespace std;

int main()
{
    double budget;
    int vga_count, cpu_count, ram_count;
    cin >> budget >> vga_count >> cpu_count >> ram_count;

    double vga_total_price = vga_count * 250;
    double total_price = vga_total_price + cpu_count * vga_total_price * 0.35 + ram_count * vga_total_price * 0.10;

    if (vga_count > cpu_count)
    {
        total_price *= 0.85;
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    if (budget >= total_price)
    {
        cout << "You have " << budget - total_price << " leva left!" << "\n";
    }
    else
    {
        cout << "Not enough money! You need " << total_price - budget << " leva more!" << "\n";
    }
    return 0;
}