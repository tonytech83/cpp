//
// Created by TonyTech on 10.1.2025 г..
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string company_name;
    getline(cin, company_name);

    int adults_ticket, kids_ticket;
    double adult_ticket_price, support_tax;
    cin >> adults_ticket >> kids_ticket >> adult_ticket_price >> support_tax;

    const double kid_ticket_price = adult_ticket_price * 0.3 + support_tax;
    adult_ticket_price += support_tax;

    const double profit = adults_ticket * adult_ticket_price + kids_ticket * kid_ticket_price;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The profit of your agency from " << company_name << " tickets is " << profit * 0.2 << " lv." << endl;

    return 0;
}
