//
// Created by tonytech on 02.09.2025.
//

#ifndef CPP_PARSECOMPANIES_H
#define CPP_PARSECOMPANIES_H

#include <memory>
#include <set>
#include <sstream>
#include <vector>

#include "Company.h"

class CompanyFactory {
    std::istringstream iss;
    int &numCompanies;
    std::string (*idGen)(const Company &c);

public:
    CompanyFactory(const std::string &input, int &numCompanies, std::string (*idGen)(const Company &c)) :
        iss(input), numCompanies(numCompanies), idGen(idGen) {};

    auto create() -> Company * {
        numCompanies = 0;
        std::vector<Company> companies;
        std::set<std::string> ids;

        int id;
        std::string name;
        while (iss >> id >> name) {
            Company company(id, name);
            std::string uniqueId = idGen(company);
            if (ids.find(uniqueId) == ids.end()) {
                companies.emplace_back(company);
                ids.insert(uniqueId);
                numCompanies++;
            }
        }


        auto *arr = new Company[numCompanies];
        for (int i = 0; i < numCompanies; i++) {
            arr[i] = companies[i];
        }

        return arr;
    };
};


inline auto parseUniqueCompanies(const std::string &input, int &numCompanies, std::string (*idGen)(const Company &c))
        -> Company * {
    CompanyFactory factory(input, numCompanies, idGen);

    return factory.create();
}

#endif // CPP_PARSECOMPANIES_H
