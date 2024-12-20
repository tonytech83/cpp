//
// Created by TonyTech on 20.12.2024 г..
//

#include <iostream>
#include <string>

int main() {
    std::string username, password;
    std::cin >> username >> password;

    std::string input;
    std::cin >> input;

    while (input != password) {
        std::cin >> input;
    }

    std::cout << "Welcome " << username << "!"<< std::endl;

    return 0;
}