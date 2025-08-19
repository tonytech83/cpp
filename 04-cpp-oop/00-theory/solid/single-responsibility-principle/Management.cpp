//
// Created by tonytech on 18.08.2025.
//
#include "Management.h"

auto Management::AddEmployee(const Employee &e)->void { employees.push_back(e); }

// Not need method SaveToFile after implementation of FileWriter class
// auto Management::SaveToFile() const -> void {
//     for (const auto &employee : employees) {
//         employee.SaveToFile();
//     }
// }
