#include <iostream>
#include <string>

int main()
{
    std::string projection_type;
    int rows, cols;
    std::cin >> projection_type >> rows >> cols;

    double price;

    if (projection_type == "Premiere")
    {
        price = 12.00;
    }
    else if (projection_type == "Normal")
    {
        price = 7.50;
    }
    else
    {
        price = 5.00;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << price * rows * cols << std::endl;

    return 0;
}
