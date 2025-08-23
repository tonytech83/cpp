//
// Created by tonytech on 23.8.2025.
//

#ifndef CPP_VECTORCOMPARISONS_H
#define CPP_VECTORCOMPARISONS_H

#include "Vector.h"


struct VectorLengthComparer {
    auto operator()(const Vector &a, const Vector &b) const -> bool { return a.getLength() < b.getLength(); }
};

template<class T, class Comparator>
struct ReverseComparer {
    Comparator comparator;
    auto operator()(const Vector &a, const Vector &b) const -> bool { return !comparator(a, b); }
};

#endif // CPP_VECTORCOMPARISONS_H
