//
// Created by tonytech on 18.08.2025.
//
#include <iostream>
#include "Management.h"

auto main() -> int {
    Employee e1(0, "Ivan", 5000);
    Employee e2(1, "Mariya", 6000);

    Management management;
    management.AddEmployee(e1);
    management.AddEmployee(e2);

    management.SaveToFile();

    return 0;
}
