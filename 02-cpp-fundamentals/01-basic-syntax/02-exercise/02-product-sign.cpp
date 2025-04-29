#include <iostream>
using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;

    if (a == 0 || b == 0 || c == 0) {
        cout << '+' << endl;
    } else {
        int plusCounter = 0;

        if (a > 0) {
            plusCounter++;
        }
        if (b > 0) {
            plusCounter++;
        }
        if (c > 0) {
            plusCounter++;
        }

        if (plusCounter % 2 != 0)
            cout << '+' << endl;
        else
            cout << '-' << endl;
    }

    return 0;
}
