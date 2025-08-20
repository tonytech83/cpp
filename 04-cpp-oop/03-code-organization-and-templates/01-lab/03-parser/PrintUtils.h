//
// Created by tonytech on 19.08.2025.
//

#ifndef CPP_PRINTUTILS_H
#define CPP_PRINTUTILS_H

#include <vector>
#include <iostream>

template<typename T>
auto printVector(const std::vector<T> &vec) -> void {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

#endif // CPP_PRINTUTILS_H
