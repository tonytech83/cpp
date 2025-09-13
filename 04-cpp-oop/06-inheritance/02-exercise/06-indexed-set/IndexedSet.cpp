//
// Created by tonytech on 12.09.2025.
//

#include "IndexedSet.h"

#include <iostream>
using namespace std;

IndexedSet::IndexedSet() : valuesArray(nullptr) {};

// Copy constructor
IndexedSet::IndexedSet(const IndexedSet &other) : IndexedSet() { *this = other; }

auto IndexedSet::add(const Value &v) -> void {
    if (this->valuesSet.insert(v).second == true)
        // we have insert, which invalidate our `valuesArray`
        clearIndex(); // The set is not same, clear it!
};

auto IndexedSet::size() const -> size_t { return valuesSet.size(); }

auto IndexedSet::operator[](size_t index) -> const Value & {
    if (valuesArray == nullptr)
        buildIndex();

    if (index >= valuesSet.size())
        // index out of bound exception!
        // DO SOMETHING!
        ;
    return this->valuesArray[index];
}


auto IndexedSet::operator=(const IndexedSet &other) -> IndexedSet & {
    if (this == &other)
        return *this; // assigning to ourselves

    clearIndex(); // invalidate the cache
    this->valuesSet = other.valuesSet;

    return *this;
}

IndexedSet::~IndexedSet() { clearIndex(); }

auto IndexedSet::buildIndex() -> void {
    auto *newValues = new Value[valuesSet.size()]; // take memory with size of our `valuesSet`

    int idx = 0;
    for (const auto v: this->valuesSet)
        newValues[idx++] = v;

    clearIndex(); // prevent memory leak!
    this->valuesArray = newValues;
}
auto IndexedSet::clearIndex() -> void {
    delete[] this->valuesArray;
    this->valuesArray = nullptr;
}
