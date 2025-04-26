#include <iostream>
#include <string>

int main() {
    std::string month;
    int number_of_nights;
    std::cin >> month >> number_of_nights;

    double studio_price, apartment_price;

    if (month == "May" || month == "October") {
        studio_price = number_of_nights * 50;
        apartment_price = number_of_nights * 65;

        if (number_of_nights > 7 && number_of_nights <= 14) {
            studio_price *= 0.95;
        } else if (number_of_nights > 14) {
            studio_price *= 0.7;
            apartment_price *= 0.9;
        }
    } else if (month == "June" || month == "September") {
        studio_price = number_of_nights * 75.2;
        apartment_price = number_of_nights * 68.70;

        if (number_of_nights > 14) {
            studio_price *= 0.8;
            apartment_price *= 0.9;
        }
    } else {
        studio_price = number_of_nights * 76;
        apartment_price = number_of_nights * 77;
        if (number_of_nights > 14) {
            apartment_price *= 0.9;
        }
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << "Apartment: " << apartment_price << " lv." << std::endl;
    std::cout << "Studio: " << studio_price << " lv." << std::endl;

    return 0;
}
