#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    const double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        cout << (-b + sqrt(discriminant)) / (2 * a) << ' ' << (-b - sqrt(discriminant)) / (2 * a) << endl;
    } else if (discriminant == 0) {
        cout << -b / (2 * a) << endl;
    } else {
        cout << "no roots" << endl;
    }

    return 0;
}