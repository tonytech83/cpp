//
// Created by tonytech on 17.09.2025.
//

#ifndef CPP_REMOVEDUPLICATES_H
#define CPP_REMOVEDUPLICATES_H

#endif // CPP_REMOVEDUPLICATES_H

#include <list>
#include <set>
#include "Company.h"

inline void removeDuplicates(std::list<Company *>::iterator itCompany, std::list<Company *> &companies) {
    // current company
    const Company *orgCompany = *itCompany;

    std::set<Company *> duplicates;

    ++itCompany;
    while (itCompany != companies.end()) {
        if (orgCompany == *itCompany) {
            // the same pointer, remove it from the list
            itCompany = companies.erase(itCompany);
        } else if ((*itCompany)->getName() == orgCompany->getName()) {
            // lazy delete - mark the pointer for deletion!
            duplicates.insert(*itCompany);
            itCompany = companies.erase(itCompany);
        } else
            ++itCompany;
    }

    // Delete duplicates
    for (const auto company : duplicates) {
        delete company;
    }
}

inline auto removeDuplicates(std::list<Company *> &companies) -> void {
    auto itCurrentCompany = companies.begin();
    while (itCurrentCompany != companies.end()) {
        removeDuplicates(itCurrentCompany, companies);
        ++itCurrentCompany;
    }
}
