//
// Created by tonytech on 15.09.2025.
//

#ifndef CPP_RANGE_H
#define CPP_RANGE_H


class Range {
    int from, to;

public:
    Range(const int &from, const int &to);

    [[nodiscard]] auto isInRange(const int &checkNumber) const -> bool;

    auto print() const -> void;
};


#endif // CPP_RANGE_H
