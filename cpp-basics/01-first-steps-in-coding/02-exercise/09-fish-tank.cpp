#include <iostream>

using namespace std;

int main()
{
    int length, width, heigh;
    double percent;
    cin >> length >> width >> heigh >> percent;

    double totalVolume = length * width * heigh;
    double waterVolume = (totalVolume * (100 - percent) / 100) / 1000;

    cout << waterVolume << endl;

    return 0;
}