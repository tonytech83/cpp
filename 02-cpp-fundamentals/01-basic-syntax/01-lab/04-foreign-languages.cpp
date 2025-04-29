//
// Created by tonytech on 4/26/25.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string countryName;
    cin >> countryName;

    if (countryName == "USA" || countryName == "England") {
        cout << "English";
    } else if (countryName == "Spain" || countryName == "Argentina" || countryName == "Mexico") {
        cout << "Spanish";
    } else {
        cout << "unknown";
    }
    cout << endl;

    return 0;
}
