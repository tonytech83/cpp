# include <iostream>

int main() {
    std::string product_name, town_name;
    double quantity, price;
    std::cin >> product_name >> town_name >> quantity;

    if (town_name == "Sofia") {
        if (product_name == "coffee") {
            price = quantity * 0.5;
        } else if (product_name == "water") {
            price = quantity * 0.80;
        } else if (product_name == "beer") {
            price = quantity * 1.2;
        } else if (product_name == "sweets") {
            price = quantity * 1.45;
        } else {
            price = quantity * 1.6;
        }
    } else if (town_name == "Plovdiv") {
        if (product_name == "coffee") {
            price = quantity * 0.4;
        } else if (product_name == "water") {
            price = quantity * 0.70;
        } else if (product_name == "beer") {
            price = quantity * 1.15;
        } else if (product_name == "sweets") {
            price = quantity * 1.30;
        } else {
            price = quantity * 1.50;
        }
    } else {
        if (product_name == "coffee") {
            price = quantity * 0.45;
        } else if (product_name == "water") {
            price = quantity * 0.70;
        } else if (product_name == "beer") {
            price = quantity * 1.1;
        } else if (product_name == "sweets") {
            price = quantity * 1.35;
        } else {
            price = quantity * 1.55;
        }
    }

    std::cout << price << "\n";

    return 0;
}
