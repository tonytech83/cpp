#include <iostream>

using namespace std;

int main()
{
    const double protectiveNylonPrice = 1.50;
    const double paintPrice = 14.50;
    const double paintThinnerPrice = 5.00;

    int protectiveNylon, paint, paintThinner, hours;

    cin >> protectiveNylon >> paint >> paintThinner >> hours;

    double totalBeforeWork = (protectiveNylon + 2) * protectiveNylonPrice + paint * 1.1 * paintPrice + paintThinner * paintThinnerPrice + 0.40;
    double workTotal = totalBeforeWork * 0.3 * hours;
    double total = totalBeforeWork + workTotal;

    cout << total << endl;

    return 0;
}