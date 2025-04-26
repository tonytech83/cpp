#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int pagesCount, pagesPerHour, days;

    cin >> pagesCount >> pagesPerHour >> days;

    cout << pagesCount / pagesPerHour / days << endl;

    return 0;
}