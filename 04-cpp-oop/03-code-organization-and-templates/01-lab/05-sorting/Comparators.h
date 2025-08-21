//
// Created by tonytech on 20.08.2025.
//

#ifndef CPP_COMPARATORS_H
#define CPP_COMPARATORS_H

template<class T>
class LessThan {
public:
    auto operator()(const T &a, const T &b) const -> bool { return a < b; }
};

template<class T, class Comparator>
class Reverse {
public:
    auto operator()(const T &a, const T &b) const -> bool {
        Comparator comp;
        return !comp(a, b);
    }
};

#endif // CPP_COMPARATORS_H
