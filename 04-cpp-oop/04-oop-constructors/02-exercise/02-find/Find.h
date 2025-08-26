//
// Created by tonytech on 26.08.2025.
//

#ifndef CPP_FIND_H
#define CPP_FIND_H

#include <algorithm>
#include <vector>
#include "Company.h"

class Finder {
    std::vector<Company *> &companies;
    int searchId;

public:
    Finder(std::vector<Company *> &companies, const int &searchId) : companies(companies), searchId(searchId) {}

    [[nodiscard]] auto find_linear() const -> Company * {
        std::vector<Company *>::const_iterator it;
        for (it = this->companies.begin(); it != this->companies.end(); ++it)
            if ((*it)->getId() == searchId)
                return *it;

        return nullptr;
    }

    [[nodiscard]] auto find_functor() const -> Company * {
        const struct findData {
            int searchId;

            explicit findData(const int searchId) : searchId(searchId) {}

            auto operator()(const Company *curr) const -> bool { return curr->getId() == searchId; }

        } findD(searchId);

        const auto it = find_if(this->companies.begin(), this->companies.end(), findD);

        return it == this->companies.end() ? nullptr : *it;
    }

    [[nodiscard]] auto find_lambda() const {
        const auto it = find_if(this->companies.begin(), this->companies.end(),
                                [this](const Company *curr) -> bool { return curr->getId() == this->searchId; });

        return it == this->companies.end() ? nullptr : *it;
    }
};

inline auto find(std::vector<Company *> &companies, const int &searchId) -> Company * {
    const Finder f(companies, searchId);

    // return f.find_linear();
    // return f.find_linear();
    return f.find_lambda();
}

#endif // CPP_FIND_H
