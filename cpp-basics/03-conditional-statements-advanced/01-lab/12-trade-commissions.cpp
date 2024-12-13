#include <iomanip>
#include <iostream>

int main() {

    std::string town;
    double sales_volume;
    double trade_commission;
    std::cin >> town >> sales_volume;

    if (sales_volume < 0) {
        std::cout << "error\n";
        return 0;
    }

    if (town == "Sofia") {
        if (sales_volume >= 0 && sales_volume <= 500) {
            trade_commission = sales_volume * 0.05;
        } else if (sales_volume > 500 && sales_volume <= 1000) {
            trade_commission = sales_volume * 0.07;
        } else if (sales_volume > 1000 && sales_volume <= 10000) {
            trade_commission = sales_volume * 0.08;
        } else {
            trade_commission = sales_volume * 0.12;
        }
    } else if (town == "Varna") {
        if (sales_volume >= 0 && sales_volume <= 500) {
            trade_commission = sales_volume * 0.045;
        } else if (sales_volume > 500 && sales_volume <= 1000) {
            trade_commission = sales_volume * 0.075;
        } else if (sales_volume > 1000 && sales_volume <= 10000) {
            trade_commission = sales_volume * 0.1;
        } else {
            trade_commission = sales_volume * 0.13;
        }
    } else if (town == "Plovdiv") {
        if (sales_volume >= 0 && sales_volume <= 500) {
            trade_commission = sales_volume * 0.055;
        } else if (sales_volume > 500 && sales_volume <= 1000) {
            trade_commission = sales_volume * 0.08;
        } else if (sales_volume > 1000 && sales_volume <= 10000) {
            trade_commission = sales_volume * 0.12;
        } else {
            trade_commission = sales_volume * 0.145;
        }
    } else {
        std::cout << "error\n";
        return 0;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << trade_commission << '\n';

    return 0;
}
