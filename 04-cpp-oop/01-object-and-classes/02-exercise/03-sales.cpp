//
// Created by tonytech on 10.8.2025.
//
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Sale {
    string town;
    string product;
    double price;
    double quantity;

public:
    Sale(const string &town, const string &product, const double &price, const double &quantity) {
        this->town = town;
        this->product = product;
        this->price = price;
        this->quantity = quantity;
    }

    [[nodiscard]] auto total() const -> double { return this->price * this->quantity; }
};

auto main() -> int {
    map<string, double> salesByTown;

    int salesCount;
    cin >> salesCount;

    while (salesCount--) {
        string town, product;
        double price = 0, quantity = 0;
        cin >> town >> product >> price >> quantity;
        Sale sale(town, product, price, quantity);
        salesByTown[town] += sale.total();
    }

    for (const auto &[town, total]: salesByTown)
        cout << town << " -> " << fixed << setprecision(2) << total << '\n';

    return 0;
}
