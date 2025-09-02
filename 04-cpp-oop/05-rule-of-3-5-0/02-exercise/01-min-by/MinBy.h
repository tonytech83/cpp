//
// Created by tonytech on 30.8.2025.
//

#ifndef CPP_MINBY_H
#define CPP_MINBY_H

#include <vector>

template<class T, class Comparator>
auto minBy(const std::vector<T> &values, Comparator *comparator) -> T {
    T result = values[0];

    for (const auto &curr: values)
        if (comparator(curr, result))
            result = curr;

    return result;
}

#endif // CPP_MINBY_H
