#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    string tv_show_name;
    double episode_duration, lunch_break_duration;
    getline(cin, tv_show_name);
    cin >> episode_duration >> lunch_break_duration;

    double lunch_duration = lunch_break_duration / 8;
    double relax_duration = lunch_break_duration / 4;

    double time_to_watch = lunch_break_duration - lunch_duration - relax_duration;

    if (time_to_watch >= episode_duration)
    {
        cout << "You have enough time to watch " << tv_show_name << " and left with " << ceil(time_to_watch - episode_duration) << " minutes free time." << "\n";
    }
    else
    {
        cout << "You don't have enough time to watch " << tv_show_name << ", you need " << ceil(episode_duration - time_to_watch) << " more minutes." << "\n";
    }

    return 0;
}