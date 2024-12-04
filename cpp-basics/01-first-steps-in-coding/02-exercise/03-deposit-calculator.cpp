#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double deposit, interestRate, sum;
    int period;

    cin >> deposit >> period >> interestRate;

    sum = deposit + period * ((deposit * interestRate / 100) / 12);

    cout << sum << endl;

    return 0;
}