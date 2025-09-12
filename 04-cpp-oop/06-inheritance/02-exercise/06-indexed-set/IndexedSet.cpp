//
// Created by tonytech on 12.09.2025.
//

#include "IndexedSet.h"

// IndexedSet::IndexedSet() {};

IndexedSet::IndexedSet(const IndexedSet &other) {
    this->valuesArray = other.valuesArray;
    this->valuesSet = other.valuesSet;
}

auto IndexedSet::add(const Value &v) -> void {};

auto IndexedSet::size() const -> size_t { return valuesSet.size(); }

auto IndexedSet::operator[](size_t index) const -> const Value & {
    Value a;
    return *a;
}

auto IndexedSet::operator=(const IndexedSet &other) -> IndexedSet & {
    if (this != &other) {
        this->valuesArray = other.valuesArray;
        this->valuesSet = other.valuesSet;
    }
    return *this;
}

IndexedSet::~IndexedSet() { this->valuesArray = nullptr; }

auto IndexedSet::buildIndex() -> void {}
auto IndexedSet::clearIndex() -> void {}
