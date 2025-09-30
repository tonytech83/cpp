//
// Created by tonytech on 30.9.2025.
//

#include <algorithm>

#include "Range.h"

Range::Range() : rangeFirst(0), rangeLength(0), valueCounts(nullptr) {}

auto Range::add(T value) -> void {
    const T first = this->rangeFirst;
    const T last = this->rangeFirst + this->rangeLength - 1;

    if (empty())
        resize(value, value);
    else if (value < first)
        resize(value, last);
    else if (value > last)
        resize(first, value);

    valueCounts[getIndex(value)]++;
}

auto Range::getCount(T value) const -> size_t {
    if (empty())
        return 0;

    // FIX: inclusive upper bound should be (rangeFirst + rangeLength - 1)
    if (value < rangeFirst || value > rangeFirst + rangeLength - 1)
        return 0;

    return valueCounts[getIndex(value)];
}

auto Range::clear() -> void {
    rangeFirst = 0;
    rangeLength = 0;
    if (valueCounts != nullptr)
        delete[] valueCounts;
    valueCounts = nullptr;
}

auto Range::resize(T first, T last) -> void {
    T newFirst = first;
    T newLength = last - first + 1;

    auto *newCounts = new size_t[newLength]{};

    if (!empty()) {
        std::copy(valueCounts, valueCounts + rangeLength, newCounts + (rangeFirst - newFirst));
        clear();
    }
    rangeFirst = newFirst;
    rangeLength = newLength;
    valueCounts = newCounts;
}

auto Range::empty() const -> bool { return rangeLength == 0; }

Range::Range(const Range &other) : Range() { *this = other; }

auto Range::operator=(const Range &other) -> Range & {
    clear();
    valueCounts = copyValues(other.valueCounts, other.rangeLength);
    rangeFirst = other.rangeFirst;
    rangeLength = other.rangeLength;

    return *this;
}

Range::~Range() { clear(); }

auto Range::getIndex(T value) const -> size_t { return value - rangeFirst; }
