//
// Created by tonytech on 30.9.2025.
//

#ifndef CPP_CITYUTILS_H
#define CPP_CITYUTILS_H

#include <algorithm>
#include <utility>
#include <vector>

#include "City.h"

inline auto initCity(const std::string &name, const size_t &population) -> City * { return new City(name, population); }

inline auto groupByPopulation(const std::vector<const City *> &cities, size_t &totalPopulation)
        -> std::vector<std::pair<size_t, const City *>> {

    totalPopulation = 0;
    std::vector<std::pair<size_t, const City *>> sortedCities;
    sortedCities.reserve(cities.size());

    for (const auto city: cities) {
        sortedCities.emplace_back(city->getPopulation(), city);
        totalPopulation += city->getPopulation();
    }

    // sort by population
    std::sort(sortedCities.begin(), sortedCities.end(), [](const auto &a, const auto &b) { return a.first < b.first; });

    return sortedCities;
}

#endif // CPP_CITYUTILS_H
