//
// Created by tonytech on 6/21/25.
//
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;


int main() {
    int dayFoodQuantity;
    cin >> dayFoodQuantity;
    cin.ignore();

    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer);

    queue<int> orders;

    int biggestOrder = INT_MIN;
    int order;
    while (iss >> order) {
        if (order > biggestOrder)
            biggestOrder = order;
        orders.push(order);
    }

    cout << biggestOrder << endl;

    const int ordersSize = orders.size();

    for (int i = 0; i < ordersSize; i++) {
        int currOrder = orders.front();
        if (dayFoodQuantity - currOrder >= 0) {
            orders.pop();
            dayFoodQuantity -= currOrder;
        }
    }

    if (orders.empty())
        cout << "Orders complete" << endl;
    else {
        cout << "Orders left: ";

        while (!orders.empty()) {
            cout << orders.front() << ' ';
            orders.pop();
        }
    }

    return 0;
}
