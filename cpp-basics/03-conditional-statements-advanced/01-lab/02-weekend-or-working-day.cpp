#include <iostream>
#include <string>

int main()
{
    std::string day;
    std::getline(std::cin, day);

    if (day == "Saturday" || day == "Sunday")
    {
        std::cout << "Weekend" << "\n";
    }
    else if (day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day == "Friday")
    {
        std::cout << "Working day" << "\n";
    }
    else
    {
        std::cout << "Error" << "\n";
    }

    return 0;
}