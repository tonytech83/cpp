#include <iostream>
#include <string>

int main() {
    std::string day;
    std::cin >> day;

    if (day == "Monday" or day == "Tuesday" or day == "Friday") {
        std::cout << 12 << std::endl;
    } else if (day == "Wednesday" or day == "Thursday") {
        std::cout << 14 << std::endl;
    } else {
        std::cout << 16 << std::endl;
    }

    return 0;
}
