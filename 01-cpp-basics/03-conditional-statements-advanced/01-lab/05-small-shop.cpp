# include <iostream>

int main() {
    std::string product_name, town_name;
    double quantity, price;
    std::cin >> product_name >> town_name >> quantity;

    if (town_name == "Sofia") {
        if (product_name == "coffee") {
            price = 0.5;
        } else if (product_name == "water") {
            price = 0.80;
        } else if (product_name == "beer") {
            price = 1.2;
        } else if (product_name == "sweets") {
            price = 1.45;
        } else {
            price = 1.6;
        }
    } else if (town_name == "Plovdiv") {
        if (product_name == "coffee") {
            price = 0.4;
        } else if (product_name == "water") {
            price = 0.70;
        } else if (product_name == "beer") {
            price = 1.15;
        } else if (product_name == "sweets") {
            price = 1.30;
        } else {
            price = 1.50;
        }
    } else {
        if (product_name == "coffee") {
            price = 0.45;
        } else if (product_name == "water") {
            price = 0.70;
        } else if (product_name == "beer") {
            price = 1.1;
        } else if (product_name == "sweets") {
            price = 1.35;
        } else {
            price = 1.55;
        }
    }

    std::cout << price * quantity << "\n";

    return 0;
}
