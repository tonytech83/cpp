//
// Created by tonytech on 26.08.2025.
//

#ifndef CPP_ORDEREDINSERTER_H
#define CPP_ORDEREDINSERTER_H

#include "Company.h"

#include <algorithm>
#include <vector>

class OrderedInserter {
    std::vector<const Company *> &companies;

    [[nodiscard]] auto findIdxToInsert(const int &companyId) const -> std::vector<const Company *>::iterator {
        auto it = companies.begin();
        for (; it != companies.end(); ++it) {
            if ((*it)->getId() > companyId) {
                // return it;
                break;
            }
        }
        // return companies.end();
        return it;
    }

    [[nodiscard]] auto findIdxToInsert_lambda(const int &companyId) const -> std::vector<const Company *>::iterator {
        auto findIdx = [&](const Company *curr) -> bool { return curr->getId() > companyId; };
        const auto it = find_if(this->companies.begin(), this->companies.end(), findIdx);

        return it == this->companies.end() ? this->companies.end() : it;
    }


public:
    explicit OrderedInserter(std::vector<const Company *> &companies) : companies(companies) {}

    auto insert(const Company *curr) const -> void { companies.insert(findIdxToInsert(curr->getId()), curr); }
    // auto insert(const Company *curr) const -> void { companies.insert(findIdxToInsert_lambda(curr->getId()), curr); }
};

#endif // CPP_ORDEREDINSERTER_H
