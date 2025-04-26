#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    constexpr int BOOK_PAGES = 899;
    constexpr int BOOK_COVERS = 2;

    double pagePrice, coverPrice, designerCheck;
    int percentDiscount, percentPaidByTeam;

    cin >> pagePrice >> coverPrice >> percentDiscount >> designerCheck >> percentPaidByTeam;

    const double totalPagesPrice = pagePrice * BOOK_PAGES + coverPrice * BOOK_COVERS;
    const double priceWithDiscount = totalPagesPrice * (1 - percentDiscount / 100.0);
    const double priceWithDesignerCheck = priceWithDiscount + designerCheck;
    const double finalCost = priceWithDesignerCheck * (1 - percentPaidByTeam / 100.0);

    cout << fixed << setprecision(2) << "Avtonom should pay " << finalCost << " BGN." << endl;


    return 0;
}
