//
// Created by tonytech on 19.08.2025.
//

#include "FileWriter.h"
#include <iostream>
#include "Management.h"

auto FileWriter::SaveToFile(const Management &m) -> void {
    auto employees = m.GetEmployees();

    for (const auto &employee: employees) {
        SaveEmployee(employee);
    }
}

auto FileWriter::SaveEmployee(const Employee &e) -> void {
    std::cout << e.GetName() << " Saved to file - Changed!" << std::endl;
}
