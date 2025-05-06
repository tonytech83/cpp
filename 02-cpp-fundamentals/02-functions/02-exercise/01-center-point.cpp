//
// Created by tonytech on 5/6/25.
//

#include <cmath>
#include <iostream>
using namespace std;

double calcMedian(double x, double y);

void printPoint(double x, double y);


int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double medianOne = calcMedian(x1, y1);
    double medianTwo = calcMedian(x2, y2);

    if (medianOne <= medianTwo)
        printPoint(x1, y1);
    else
        printPoint(x2, y2);

    cout << endl;

    return 0;
}

void printPoint(const double x, const double y) {
    cout << '(' << x << ", " << y << ')';
}

double calcMedian(const double x, const double y) {
    return sqrt((pow(x, 2) + pow(y, 2)) / 4);
}
