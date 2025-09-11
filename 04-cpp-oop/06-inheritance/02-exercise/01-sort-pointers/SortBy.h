#ifndef SORT_BY_H
#define SORT_BY_H

#include <algorithm>


#include "Company.h"

inline auto sortBy(Company **first, Company **last, bool (*comparator)(const Company &a, const Company &b)) -> void {
    std::sort(first, last, [comparator](Company *&a, Company *&b) { return comparator(*a, *b); });
}

#endif // !SORT_BY_H
