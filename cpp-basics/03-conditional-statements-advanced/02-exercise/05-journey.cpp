#include <iostream>
#include <string>

int main() {
    double budget;
    std::string season;
    std::cin >> budget >> season;

    std::string location;
    std::string vacation_type;
    double vacation_price;

    if (budget <= 100) {
        location = "Bulgaria";
        if (season == "summer") {
            vacation_type = "Camp";
            vacation_price = budget * 0.3;
        } else {
            vacation_type = "Hotel";
            vacation_price = budget * 0.7;
        }
    } else if (budget <= 1000) {
        location = "Balkans";
        if (season == "summer") {
            vacation_type = "Camp";
            vacation_price = budget * 0.4;
        } else {
            vacation_type = "Hotel";
            vacation_price = budget * 0.8;
        }
    } else {
        location = "Europe";
        vacation_type = "Hotel";
        vacation_price = budget * 0.9;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << "Somewhere in " << location << "" << "\n";
    std::cout << vacation_type << " - " << vacation_price << "\n";

    return 0;
}
