//
// Created by TonyTech on 23.12.2024 г..
//

#include <iostream>
#include <string>
using namespace std;

string output(const int free_volume) {
    if (free_volume < 0) {
        return "No more free space! You need " + to_string(abs(free_volume)) + " Cubic meters more.";
    }
    return to_string(abs(free_volume)) + " Cubic meters left.";
}

int main() {
    int width, length, height;
    cin >> width >> length >> height;
    int free_volume = width * length * height;

    string input;
    cin >> input;

    while (input != "Done") {
        free_volume -= stoi(input);
        if (free_volume <= 0)
            break;

        cin >> input;
    }

    cout << output(free_volume) << endl;

    return 0;
}
