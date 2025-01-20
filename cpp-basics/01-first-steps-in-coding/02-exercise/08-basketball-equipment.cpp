#include <iostream>

using namespace std;

int main()
{
    int yearTax;
    cin >> yearTax;

    double sneakers = yearTax * 0.6;
    double basketballClothes = sneakers * 0.8;
    double ball = basketballClothes / 4;
    double accessories = ball / 5;

    double total = yearTax + sneakers + basketballClothes + ball + accessories;

    cout << total << endl;

    return 0;
}