#include <iostream>
#include <string>

int main() {
    int hours;
    std::string day;
    std::cin >> hours >> day;

    if (hours >= 10 and hours <= 18 and day != "Sunday") {
        std::cout << "open" << std::endl;
    } else {
        std::cout << "closed" << std::endl;
    }

    return 0;
}
