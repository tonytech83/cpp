//
// Created by tonytech on 5/10/25.
//
#include <iostream>
#include <string>
using namespace std;

string weekDays[] = {
    "Invalid day!",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday",
};

void printDayOfWeek(string daysOfWeek[], int dayNumber) {
    if (dayNumber < 1 || dayNumber > 7)
        dayNumber = 0;

    cout << daysOfWeek[dayNumber] << endl;
}

int main() {
    int number;
    cin >> number;

    printDayOfWeek(weekDays, number);

    return 0;
}
