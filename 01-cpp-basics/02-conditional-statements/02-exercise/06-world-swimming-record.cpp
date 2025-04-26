#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double world_record, distance, seconds_per_meter;
    cin >> world_record >> distance >> seconds_per_meter;

    double time = distance * seconds_per_meter;
    double delay = floor(distance / 15) * 12.5;

    time += delay;

    cout.setf(ios::fixed);
    cout.precision(2);

    if (world_record > time)
    {
        cout << "Yes, he succeeded! The new world record is " << time << " seconds." << "\n";
    }
    else
    {
        cout << "No, he failed! He was " << time - world_record << " seconds slower." << "\n";
    }

    return 0;
}