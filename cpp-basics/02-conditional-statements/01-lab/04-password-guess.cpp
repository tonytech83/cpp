#include <iostream>

using namespace std;

int main()
{
    const string the_password = "s3cr3t!P@ssw0rd";

    string user_input;
    cin >> user_input;

    if (user_input == the_password)
    {
        cout << "Welcome" << endl;
    }
    else
    {
        cout << "Wrong password!" << endl;
    }

    return 0;
}