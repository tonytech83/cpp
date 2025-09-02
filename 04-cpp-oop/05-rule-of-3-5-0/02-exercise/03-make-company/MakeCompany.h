//
// Created by tonytech on 02.09.2025.
//

#ifndef CPP_MAKECOMPANY_H
#define CPP_MAKECOMPANY_H
#include "Company.h"
#include "memory"

// Factory pattern
// class CompanyFactory {
//     const std::vector<std::string> &properties;
//
//     auto createPtr() -> Company * {
//         const int id = stoi(this->properties[0]);
//         const std::string &name = this->properties[1];
//         std::vector<std::pair<char, char>> employees;
//
//         for (int i(2); i < this->properties.size(); i++) {
//             std::pair<char, char> initials;
//             initials.first = this->properties[i][0];
//             initials.second = this->properties[i][1];
//             employees.push_back(initials);
//         }
//
//         return new Company(id, name, employees);
//     }
//
// public:
//     explicit CompanyFactory(const std::vector<std::string> &properties) : properties(properties) {}
//
//     auto createSharedPtr() -> std::shared_ptr<Company> { return std::shared_ptr<Company>(createPtr()); }
// };
//
// inline auto makeCompany(const std::vector<std::string> &properties) -> std::shared_ptr<Company> {
//     return CompanyFactory(properties).createSharedPtr();
// }

inline auto makeCompany(const std::vector<std::string> &properties) -> std::shared_ptr<Company> {
    const int id = stoi(properties[0]);
    const std::string &name = properties[1];
    std::vector<std::pair<char, char>> employees;

    for (int idx(2); idx < properties.size(); idx++) {
        std::pair<char, char> initials;
        initials.first = properties[idx][0];
        initials.second = properties[idx][1];
        employees.push_back(initials);
    }

    return std::make_shared<Company>(id, name, employees);
}

#endif // CPP_MAKECOMPANY_H
