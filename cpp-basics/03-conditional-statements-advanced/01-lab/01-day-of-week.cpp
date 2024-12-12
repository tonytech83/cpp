#include <iostream>

using namespace std;

int main()
{
    int user_input;
    cin >> user_input;

    if (user_input == 1)
        cout << "Monday" << "\n";
    else if (user_input == 2)
        cout << "Tuesday" << "\n";
    else if (user_input == 3)
        cout << "Wednesday" << "\n";
    else if (user_input == 4)
        cout << "Thursday" << "\n";
    else if (user_input == 5)
        cout << "Friday" << "\n";
    else if (user_input == 6)
        cout << "Saturday" << "\n";
    else if (user_input == 7)
        cout << "Sunday" << "\n";
    else
        cout << "Error" << "\n";

    return 0;
}