//
// Created by tonytech on 30.9.2025.
//

#ifndef CPP_INCLUDES_H
#define CPP_INCLUDES_H

#include <iostream>
#include <vector>

#include "City.h"

struct CityDiff {
    const City a, b;
    CityDiff(const City &a, const City &b) : a(a), b(b) {}
};

inline auto operator-(const City &first, const City &second) -> CityDiff { return CityDiff(first, second); }

inline auto operator>>(std::istream &in, City &c) -> std::istream & {

    std::string name;
    size_t population;
    unsigned int censusYear;

    in >> name >> population >> censusYear;

    c = City(censusYear, name, population);

    return in;
}

inline auto operator<<(std::ostream &out, const CityDiff &diff) -> std::ostream & {
    const City &first = diff.a;
    const City &second = diff.b;

    // check for equal city names
    if (first.getName() == second.getName()) { // same names
        out << first.getName() << " (" << first.getCensusYear() << " vs. " << second.getCensusYear() << ')'
            << std::endl;

    } else { // different names
        out << first.getName() << " (" << first.getCensusYear() << ") vs. " << second.getName() << " ("
            << second.getCensusYear() << ')' << std::endl;
    }

    const int populationDiff = static_cast<int>(first.getPopulation() - second.getPopulation());
    out << "population: " << (populationDiff >= 0 ? "+" : "") << populationDiff << std::endl;

    return out;
}

#endif // CPP_INCLUDES_H
