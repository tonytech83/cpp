#include <iostream>

int main() {
    double age;
    char sex;
    std::cin >> age >> sex;

    if (age < 16) {
        if (sex == 'f') {
            std::cout << "Miss" << "\n";
        } else {
            std::cout << "Master" << "\n";
        }
    } else {
        if (sex == 'f') {
            std::cout << "Ms." << "\n";
        } else {
            std::cout << "Mr." << "\n";
        }
    }

    return 0;
}
