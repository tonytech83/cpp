//
// Created by tonytech on 07.07.2025.
//
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

auto readCompany(istream &istr) -> void * {
    // Elements to save:
    // int id; (4 bytes)
    // char []; (?)

    string line;
    getline(istr, line);

    istringstream iss(line);
    int id;
    iss >> id;
    string companyName;
    getline(iss, companyName);
    if (companyName.empty())
        return nullptr;

    const int neededBuff = sizeof(int) + companyName.length() + 1;
    char *currCompany = new char[neededBuff];

    int *idLocation = (int *) currCompany;
    *idLocation = id;
    char *nameLocation = currCompany + sizeof(int);
    strcpy(nameLocation, companyName.c_str());

    return currCompany;
}

auto printCompany(void *company) -> void {
    // the `company` variable is void pointer
    // take `id` from beginning of company
    const int *idPrt = static_cast<int *>(company);
    // take company `name` form beginning of company + size of one int (4 bytes)
    const char *namePrt = static_cast<char *>(company) + sizeof(int);

    cout << *idPrt << ' ' << namePrt << endl;
}

auto hasValidId(void *company) -> bool {
    const int *idPrt = static_cast<int *>(company);

    return *idPrt > 0;
}

auto main() -> int {
    string line;

    vector<void *> companies;

    while (true) {
        void *currCompany = readCompany(cin);
        if (currCompany == nullptr)
            break;

        companies.push_back(currCompany);
    }

    for (void *company: companies)
        if (hasValidId(company))
            printCompany(company);

    for (void *company: companies)
        delete static_cast<char *>(company);

    return 0;
}
