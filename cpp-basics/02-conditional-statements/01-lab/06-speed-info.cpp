#include <iostream>

int main()
{
    double speed;
    std::cin >> speed;

    if (speed <= 10)
        std::cout << "slow\n";
    else if (speed > 10 && speed <= 50)
        std::cout << "average\n";
    else if (speed > 50 && speed <= 150)
        std::cout << "fast\n";
    else if (speed > 150 && speed <= 1000)
        std::cout << "ultra fast\n";
    else
        std::cout << "extremely fast\n";

    return 0;
}