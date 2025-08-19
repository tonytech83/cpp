//
// Created by tonytech on 18.08.2025.
//

#include "FileWriter.h"
#include "Management.h"

auto main() -> int {
    const Employee e1(0, "Ivan", 5000);
    const Employee e2(1, "Mariya", 6000);

    Management management;
    management.AddEmployee(e1);
    management.AddEmployee(e2);

    // management.SaveToFile();
    FileWriter file;
    file.SaveToFile(management);


    return 0;
}
