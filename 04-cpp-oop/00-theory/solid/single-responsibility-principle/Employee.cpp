//
// Created by tonytech on 18.08.2025.
//
#include "Employee.h"

#include <utility>

Employee::Employee(const int id, std::string name, const double salary) :
    id(id), name(std::move(name)), salary(salary) {}

// Not need method SaveToFile after implementation of FileWriter class
// auto Employee::SaveToFile() const -> void { std::cout << name << " Saved!" << std::endl; }
