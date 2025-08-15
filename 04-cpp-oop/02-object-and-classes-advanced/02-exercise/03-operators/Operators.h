//
// Created by tonytech on 15.08.2025.
//

#ifndef CPP_OPERATORS_H
#define CPP_OPERATORS_H

#include <string>
#include <vector>

inline auto operator<<(std::vector<std::string> &vec, const std::string &s) -> std::vector<std::string> & {
    vec.push_back(s);
    return vec;
}

inline auto operator+(const std::string &s, const int &i) -> std::string { return s + std::to_string(i); }

inline auto operator<<(std::ostream &os, const std::vector<std::string> &vec) -> std::ostream & {
    for (auto &s: vec)
        os << s << std::endl;

    return os;
}

#endif // CPP_OPERATORS_H
