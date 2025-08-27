//
// Created by tonytech on 27.08.2025.
//

#ifndef CPP_PROFITREPORT_H
#define CPP_PROFITREPORT_H

#include <map>
#include <sstream>
#include "Company.h"
#include "ProfitCalculator.h"


inline auto getProfitReport(const Company *first, const Company *last, std::map<int, ProfitCalculator> &map)
        -> std::string {
    std::ostringstream output;
    auto curr = first;

    while (curr != last + 1) {
        output << curr->getName() << " = " << map[curr->getId()].calculateProfit(*curr) << std::endl;
        curr++;
    }

    return output.str();
}

// Template solution
// template<class EntityIterator>
// auto getProfitReport(EntityIterator from, EntityIterator to, std::map<int, ProfitCalculator> &map) -> std::string {
//     std::ostringstream output;
//
//     while (true) {
//         int profit = map[from->getId()].calculateProfit(*from);
//
//         output << from->getName() << " = " << profit << std::endl;
//
//         if (from == to)
//             break;
//
//         ++from;
//     }
//
//     return output.str();
// }


#endif // CPP_PROFITREPORT_H
