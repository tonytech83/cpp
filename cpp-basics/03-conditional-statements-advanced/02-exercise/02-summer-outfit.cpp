#include <iostream>
#include <string>

int main()
{
    int degrees;
    std::string time_of_day;
    std::cin >> degrees >> time_of_day;

    std::string outfit, shoes;

    if (time_of_day == "Morning")
    {
        if (degrees >= 10 && degrees <= 18)
        {
            outfit = "Sweatshirt";
            shoes = "Sneakers";
        }
        else if (degrees > 18 && degrees <= 24)
        {
            outfit = "Shirt";
            shoes = "Moccasins";
        }
        else
        {
            outfit = "T-Shirt";
            shoes = "Sandals";
        }
    }
    else if (time_of_day == "Afternoon")
    {
        if (degrees >= 10 && degrees <= 18)
        {
            outfit = "Shirt";
            shoes = "Moccasins";
        }
        else if (degrees > 18 && degrees <= 24)
        {
            outfit = "T-Shirt";
            shoes = "Sandals";
        }
        else
        {
            outfit = "Swim Suit";
            shoes = "Barefoot";
        }
    }
    else
    {
        outfit = "Shirt";
        shoes = "Moccasins";
    }

    std::cout << "It's " << degrees << " degrees, get your " << outfit << " and " << shoes << "." << std::endl;

    return 0;
}
