//
// Created by TonyTech on 20.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int projects_count;
    cin >> name >> projects_count;

    cout << "The architect " << name << " will need " << projects_count * 3 << " hours to complete " << projects_count
         << " project/s." << endl;

    return 0;
}
