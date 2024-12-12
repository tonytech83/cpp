#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

int main()
{
    std::string type;
    std::cin >> type;

    std::cout << std::fixed << std::setprecision(3);

    double area = 0;

    if (type == "square")
    {
        double side;
        std::cin >> side;

        area = side * side;
    }
    else if (type == "rectangle")
    {
        double length, width;
        std::cin >> length >> width;

        area = length * width;
    }
    else if (type == "circle")
    {
        double radius;
        std::cin >> radius;

        area = M_PI * radius * radius;
    }
    else
    {
        double length, height;
        std::cin >> length >> height;

        area = length * height / 2;
    }

    std::cout << area << std::endl;

    return 0;
}