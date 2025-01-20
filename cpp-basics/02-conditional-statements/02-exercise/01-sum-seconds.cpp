#include <iostream>

using namespace std;

int main()
{
    int first_time, second_time, third_time;
    cin >> first_time >> second_time >> third_time;

    int total_time_in_seconds = first_time + second_time + third_time;

    int minutes = total_time_in_seconds / 60;
    int seconds = total_time_in_seconds % 60;

    if (seconds < 10)
    {
        cout << minutes << ":0" << seconds << endl;
    }
    else
    {
        cout << minutes << ":" << seconds << endl;
    }

    return 0;
}