//
// Created by tonytech on 5/4/25.
//

#include <iostream>
using namespace std;

int calculateArea(int width, int height);

int main() {
    int width, height;
    cin >> width >> height;

    cout << calculateArea(width, height) << endl;

    return 0;
}

int calculateArea(const int width, const int height) {
    return width * height;
}
