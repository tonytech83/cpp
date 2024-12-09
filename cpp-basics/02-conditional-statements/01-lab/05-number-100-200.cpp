#include <iostream>

using namespace std;

int main()
{
    int user_num;
    cin >> user_num;

    if (user_num < 100)
    {
        cout << "Less than 100" << endl;
    }
    else if (user_num > 200)
    {
        cout << "Greater than 200" << endl;
    }
    else
    {
        cout << "Between 100 and 200" << endl;
    }

    return 0;
}