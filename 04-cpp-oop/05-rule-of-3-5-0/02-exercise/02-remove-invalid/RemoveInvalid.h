//
// Created by tonytech on 02.09.2025.
//

#ifndef CPP_REMOVEINVALID_H
#define CPP_REMOVEINVALID_H

#include "Company.h"

inline auto removeInvalid(std::list<Company *> &companies) -> void {

    auto it = companies.begin();
    while (it != companies.end()) {
        const Company *company = *it;
        if (company->getId() < 0) {
            delete company;
            // `erase(it)` removes the element at it and returns an iterator to the next element
            it = companies.erase(it);
        } else {
            ++it;
        }
    }

    // for (auto it = companies.begin(); it != companies.end(); ++it) {
    //     if ((*it)->getId() < 0) {
    //         delete *it;
    //         // `erase(it)` removes the element at it and returns an iterator to the next element
    //         it = companies.erase(it);
    //         // adjust iterator after erase
    //         --it;
    //     }
    // }
}

#endif // CPP_REMOVEINVALID_H
