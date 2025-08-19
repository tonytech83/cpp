//
// Created by tonytech on 18.08.2025.
//

#ifndef CPP_MANAGEMENT_H
#define CPP_MANAGEMENT_H

#include <vector>
#include "Employee.h"


class Management {
    std::vector<Employee> employees;

public:
    Management() = default;


    [[nodiscard]] auto GetEmployees() const -> std::vector<Employee> { return this->employees; }
    auto AddEmployee(const Employee &e) -> void;
    // Not need method SaveToFile after implementation of FileWriter class
    // auto SaveToFile() const -> void;
};

#endif // CPP_MANAGEMENT_H
