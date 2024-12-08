#include <iostream>

using namespace std;

int main()
{
    int first_num, second_num;
    cin >> first_num >> second_num;

    if (first_num > second_num)
    {
        cout << first_num << endl;
    }
    else
    {
        cout << second_num << endl;
    }

    return 0;
}