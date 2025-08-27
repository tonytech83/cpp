//
// Created by tonytech on 27.08.2025.
//

#include "Register.h"

// class Company;

Register::Register(const size_t numCompanies) : numAdded(0), companiesArray(new Company[numCompanies]) {}


auto Register::add(const Company &c) -> void {
    // const auto idx = static_cast<unsigned int>(this->numAdded);
    // this->companiesArray[idx] = c;
    // this->numAdded++;

    this->companiesArray[this->numAdded++] = c;
}

auto Register::get(const int companyId) const -> Company {
    size_t idx = 0;
    for (; idx < this->numAdded; idx++)
        if (this->companiesArray[idx].getId() == companyId)
            break;

    return this->companiesArray[idx];
}

Register::~Register() { delete[] this->companiesArray; }
