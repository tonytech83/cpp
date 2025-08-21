//
// Created by tonytech on 20.08.2025.
//

#ifndef CPP_PRINTUTILS_H
#define CPP_PRINTUTILS_H

#include <iostream>

template<class T>
auto printContainer(class T::iterator start, class T::iterator end) -> void {
    for (; start != end; ++start)
        std::cout << *start << ' ';
    std::cout << std::endl;
}

#endif // CPP_PRINTUTILS_H
