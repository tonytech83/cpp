//
// Created by tonytech on 18.08.2025.
//

#ifndef CPP_EMPLOYEE_H
#define CPP_EMPLOYEE_H
#include <iostream>
#include <string>

class Employee {
    int id{};
    std::string name;
    double salary{};

public:
    Employee() = default;
    Employee(int id, std::string name, double salary);

    auto SaveToFile() const -> void;

    [[nodiscard]] auto GetId() const -> int { return this->id; }
    [[nodiscard]] auto GetName() const -> std::string { return this->name; }
    [[nodiscard]] auto GetSalary() const -> double { return this->salary; }
};

#endif // CPP_EMPLOYEE_H
