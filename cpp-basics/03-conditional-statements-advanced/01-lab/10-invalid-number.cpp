#include <iostream>

int main() {
    int number;
    std::cin >> number;

    if (number < 100 || number > 200) {
        if (number != 0) {
            std::cout << "invalid" << std::endl;
        }
    }

    return 0;
}
