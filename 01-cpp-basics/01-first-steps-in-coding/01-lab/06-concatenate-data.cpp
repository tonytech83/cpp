//
// Created by TonyTech on 20.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string first_name, last_name, town;
    int age;
    cin >> first_name >> last_name >>age>> town;

    cout << "You are " << first_name << " " << last_name << ", a " << age << "-years old person from " << town << "."
         << endl;
}
