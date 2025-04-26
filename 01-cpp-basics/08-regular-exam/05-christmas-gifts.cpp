#include <iostream>
#include <string>

using namespace std;

int main() {
    constexpr double TOY_PRICE = 5.0;
    constexpr double SWEATER_PRICE = 15.0;

    int adultsCount = 0;
    int kidsCount = 0;
    double toysCost = 0.0;
    double sweaterCost = 0.0;

    string input;
    cin >> input;
    while (input != "Christmas") {
        int age = stoi(input);
        if (age <= 16) {
            toysCost += TOY_PRICE;
            kidsCount++;
        } else {
            sweaterCost += SWEATER_PRICE;
            adultsCount++;
        }

        cin >> input;
    }

    cout << "Number of adults: " << adultsCount << endl;
    cout << "Number of kids: " << kidsCount << endl;
    cout << "Money for toys: " << toysCost << endl;
    cout << "Money for sweaters: " << sweaterCost << endl;


    return 0;
}
