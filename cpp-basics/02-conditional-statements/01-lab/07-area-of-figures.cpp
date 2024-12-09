#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

int main()
{
    std::string type;
    std::cin >> type;

    std::cout << std::fixed << std::setprecision(3);

    if (type == "square")
    {
        double side;
        std::cin >> side;

        std::cout << side * side << std::endl;
    }
    else if (type == "rectangle")
    {
        double length, width;
        std::cin >> length >> width;

        std::cout << length * width << std::endl;
    }
    else if (type == "circle")
    {
        double radius;
        std::cin >> radius;

        std::cout << M_PI * radius * radius << std::endl;
    }
    else
    {
        double length, height;
        std::cin >> length >> height;

        std::cout << length * height / 2 << std::endl;
    }

    return 0;
}