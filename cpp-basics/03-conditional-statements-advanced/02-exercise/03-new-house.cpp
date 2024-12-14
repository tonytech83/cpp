#include <iostream>
#include <string>

int main()
{
    std::string flower_type;
    int flower_count, budget;
    std::cin >> flower_type >> flower_count >> budget;

    double price;

    if (flower_type == "Roses")
    {
        if (flower_count > 80)
        {
            price = 5 * 0.9;
        }
        else
            price = 5;
    }
    else if (flower_type == "Dahlias")
    {
        if (flower_count > 90)
        {
            price = 3.80 * 0.85;
        }
        else
            price = 3.80;
    }
    else if (flower_type == "Tulips")
    {
        if (flower_count > 80)
        {
            price = 2.8 * 0.85;
        }
        else
            price = 2.8;
    }
    else if (flower_type == "Narcissus")
    {
        if (flower_count < 120)
        {
            price = 3 * 1.15;
        }
        else
            price = 3;
    }
    else
    {
        if (flower_count < 80)
        {
            price = 2.5 * 1.2;
        }
        else
            price = 2.5;
    }

    double total_price = price * flower_count;

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    if (budget >= total_price)
    {
        std::cout << "Hey, you have a great garden with " << flower_count << " " << flower_type << " and "
                  << budget - total_price << " leva left." << std::endl;
    }
    else
    {
        std::cout << "Not enough money, you need " << total_price - budget << " leva more." << std::endl;
    }

    return 0;
}
