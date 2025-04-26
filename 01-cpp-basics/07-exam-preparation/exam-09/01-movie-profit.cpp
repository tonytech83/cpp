#include <iostream>
#include <string>

using namespace std;

int main() {
    string movieName;
    getline(cin, movieName);

    int daysCount, ticketsCount, cinemaPercentage;
    double ticketPrice;

    cin >> daysCount >> ticketsCount >> ticketPrice >> cinemaPercentage;

    const double ticketsPricePerDay = ticketsCount * ticketPrice;
    const double totalIncome = ticketsPricePerDay * daysCount;
    const double cinemaProfit = totalIncome * cinemaPercentage / 100;
    const double movieProfit = totalIncome - cinemaProfit;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The profit from the movie " << movieName << " is " << movieProfit << " lv." << endl;

    return 0;
}
