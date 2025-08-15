//
// Created by tonytech on 15.08.2025.
//

#ifndef CPP_SUMOFVECTORS_H
#define CPP_SUMOFVECTORS_H

#include <string>
#include <vector>


inline auto operator+(const std::vector<std::string> &a, const std::vector<std::string> &b)
        -> std::vector<std::string> {

    const size_t size = a.size();
    std::vector<std::string> result;
    result.reserve(size);

    for (size_t i = 0; i < size; i++)
        result.push_back(a[i] + ' ' + b[i]);

    return result;
}

#endif // CPP_SUMOFVECTORS_H
