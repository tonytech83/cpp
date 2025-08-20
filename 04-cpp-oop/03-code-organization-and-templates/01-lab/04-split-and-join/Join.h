//
// Created by tonytech on 20.08.2025.
//

#ifndef CPP_JOIN_H
#define CPP_JOIN_H

#include <sstream>
#include <string>
#include <vector>

template<class T>
auto join(const std::vector<T> &vec, const std::string &joinStr) -> std::string {
    std::ostringstream oss;
    for (int idx(0); idx < vec.size(); ++idx) {
        if (idx == 0)
            oss << vec[idx];
        else
            oss << joinStr << vec[idx];
    }

    return oss.str();
}

#endif // CPP_JOIN_H
