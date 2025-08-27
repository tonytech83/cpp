#ifndef REGISTER_H
#define REGISTER_H

#include "Company.h"

class Register {
    size_t numAdded;
    Company *companiesArray;

public:
    Register(size_t numCompanies);
    auto add(const Company &c) -> void;

    void add(const Company &c) const;

    Company get(int companyId) const;

    ~Register();

    Register &operator=(const Register &other) = delete;
    Register(const Register &other) = delete;
};

#endif // !REGISTER_H
