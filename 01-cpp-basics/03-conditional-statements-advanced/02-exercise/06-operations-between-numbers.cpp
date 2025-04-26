#include <iomanip>
#include <iostream>

int main() {

    int number1, number2;
    char operation;
    std::cin >> number1 >> number2 >> operation;

    if (number2 == 0 && (operation == '/' || operation == '%')) {
        std::cout << "Cannot divide " << number1 << " by zero" << '\n';
    } else {
        double result;
        std::string even_or_odd = "odd";

        if (operation == '+') {
            result = number1 + number2;
        } else if (operation == '-') {
            result = number1 - number2;
        } else if (operation == '*') {
            result = number1 * number2;
        } else if (operation == '/') {
            result = static_cast<double>(number1) / number2;
        } else {
            result = number1 % number2;
        }

        if (operation == '+' || operation == '-' || operation == '*') {
            if (static_cast<int>(result) % 2 == 0) {
                even_or_odd = "even";
            }
        }

        if (operation == '/') {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << number1 << " " << operation << " " << number2 << " = " << result << std::endl;
        } else {
            std::cout << number1 << " " << operation << " " << number2 << " = " << result;
            if (operation == '+' || operation == '-' || operation == '*') {
                std::cout << " - " << even_or_odd;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
