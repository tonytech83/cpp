//
// Created by tonytech on 03.09.2025.
//

#include "Register.h"
#include "Company.h"

#include <algorithm>

Register::Register(const size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]) {}

// Adds a Company to the array.
// It assigns c into the current position (companiesArray[numAdded]) and then increments numAdded.
auto Register::add(const Company &c) -> void { companiesArray[numAdded++] = c; }

// Searches for a Company in the array by companyId. Returns the first match it finds.
auto Register::get(const int companyId) const -> Company {
    for (int idx(0); idx < numAdded; idx++)
        if (companiesArray[idx].getId() == companyId)
            return companiesArray[idx];

    return companiesArray[0];
}

// Releases the dynamically allocated array when the Register object is destroyed.
Register::~Register() { delete[] companiesArray; }

// Copy assignment operator
// 1. Creates a deep copy of `other`.
// 2. Allocates a new array of size other.numAdded.
// 3. Copies all companies from other.companiesArray into the new array.
// 4. Deletes the old array (companiesArray) to avoid memory leaks.
// 5. Updates this object’s pointer and numAdded.
// 6. Returns *this so assignment can chain (a = b = c).
auto Register::operator=(const Register &other) -> Register & {
    auto *newArr = new Company[other.numAdded];
    std::copy(other.companiesArray, other.companiesArray + other.numAdded, newArr);

    delete[] companiesArray;

    this->companiesArray = newArr;
    this->numAdded = other.numAdded;

    return *this;
}
// Copy constructor
// 1. Delegates to the Register(size_t) constructor with 0, which initializes an empty Register.
// 2. Then uses the copy assignment operator (*this = other;) to copy contents from `other`.
// 3. Effectively, this is a deep copy: the new Register gets its own dynamically allocated array with copies of the
// companies from `other`.
Register::Register(const Register &other) : Register(0) { *this = other; }
