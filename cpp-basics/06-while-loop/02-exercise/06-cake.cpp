//
// Created by TonyTech on 23.12.2024 г..
//

#include <iostream>
#include <string>
using namespace std;

string output(const int cake_count) {
    if (cake_count < 0) {
        return "No more cake left! You need " + to_string(abs(cake_count)) + " pieces more.\n";
    }
    return to_string(cake_count) + " pieces are left.\n";
}

int main() {
    int width, length;
    cin >> width >> length;

    int cake_count = width * length;

    string input;
    cin >> input;

    while (input != "STOP" && cake_count > 0) {
        cake_count -= stoi(input);
        cin >> input;
    }

    cout << output(cake_count) << endl;

    return 0;
}
