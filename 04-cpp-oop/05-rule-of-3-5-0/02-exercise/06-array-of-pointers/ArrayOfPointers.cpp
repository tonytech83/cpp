//
// Created by tonytech on 03.09.2025.
//
#include "ArrayOfPointers.h"

using namespace std;

auto ArrayOfPointers::add(const Company *c) -> void { companies.push_back(const_cast<Company *>(c)); }

auto ArrayOfPointers::getSize() const -> size_t { return companies.size(); }

auto ArrayOfPointers::get(const size_t &companyId) const -> Company * { return companies[companyId]; }

ArrayOfPointers::~ArrayOfPointers() {
    for (const Company *c: companies)
        delete c;
}
