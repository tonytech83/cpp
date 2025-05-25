//
// Created by tonytech on 5/25/25.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> products;

    vector<string>::size_type n;
    cin >> n;
    products.reserve(n);

    for (int i = 0; i < n; i++) {
        string product;
        getline(cin, product);
        products.push_back(product);
    }

    sort(products.begin(), products.end());
    for (int i = 1; i <= n; i++) {
        cout << i << '.' << products[i - 1] << endl;
    }

    return 0;
}
