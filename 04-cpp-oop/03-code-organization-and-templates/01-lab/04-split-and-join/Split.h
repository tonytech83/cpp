//
// Created by tonytech on 20.08.2025.
//

#ifndef CPP_SPLIT_H
#define CPP_SPLIT_H

#include <iostream>
#include <sstream>
#include <vector>

template<class T>
auto split(const std::string &line, const char &separator) -> std::vector<T> {
    std::vector<T> result;
    std::istringstream iss(line);

    std::string token;
    while (std::getline(iss, token, separator)) {
        std::stringstream convert(token);
        T item;
        convert >> item;
        result.push_back(item);
    }
    return result;
}

#endif // CPP_SPLIT_H
