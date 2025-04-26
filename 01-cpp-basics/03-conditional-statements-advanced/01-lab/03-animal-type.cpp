#include <iostream>

int main()
{
    std::string animal;
    std::getline(std::cin, animal);

    if (animal == "dog")
    {
        std::cout << "mammal" << "\n";
    }
    else if (animal == "crocodile" || animal == "tortoise" || animal == "snake")
    {
        std::cout << "reptile" << "\n";
    }
    else
    {
        std::cout << "unknown" << "\n";
    }

    return 0;
}