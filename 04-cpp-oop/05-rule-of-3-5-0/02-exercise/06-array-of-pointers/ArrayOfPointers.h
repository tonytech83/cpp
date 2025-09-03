//
// Created by tonytech on 03.09.2025.
//

#ifndef CPP_ARRAYOFPOINTERS_H
#define CPP_ARRAYOFPOINTERS_H

#include "Company.h"

class ArrayOfPointers {
    std::vector<Company *> companies;

public:
    // ArrayOfPointers() : size(0), companies(nullptr) {}

    // explicit ArrayOfPointers(const int &size);
    ArrayOfPointers() : companies() {}

    auto add(const Company *) -> void;

    [[nodiscard]] auto getSize() const -> size_t;

    [[nodiscard]] auto get(const size_t &companyId) const -> Company *;

    // The rule of three, all three (Destructor, Copy assignment operator and Copy constructor) should be declared.
    ~ArrayOfPointers();

    auto operator=(const ArrayOfPointers &other) -> ArrayOfPointers & = delete;

    ArrayOfPointers(const ArrayOfPointers &other) = delete;
};

#endif // CPP_ARRAYOFPOINTERS_H
