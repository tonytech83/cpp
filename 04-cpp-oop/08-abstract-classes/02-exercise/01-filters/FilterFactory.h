//
// Created by tonytech on 30.9.2025.
//

#ifndef CPP_FILTERFACTORY_H
#define CPP_FILTERFACTORY_H

#include <string>

#include "Filter.h"

class AZFilter final : public Filter {
    auto shouldFilterOut(const char symbol) const -> bool override { return symbol >= 'A' && symbol <= 'Z'; };
};

class azFilter final : public Filter {
    auto shouldFilterOut(const char symbol) const -> bool override { return symbol >= 'a' && symbol <= 'z'; };
};

class zeroNineFilter final : public Filter {
    auto shouldFilterOut(const char symbol) const -> bool override { return symbol >= '0' && symbol <= '9'; };
};


class FilterFactory {
public:
    static auto buildFilter(const std::string &filterDefinition) -> Filter * {
        switch (filterDefinition[0]) {
            case 'A':
                return new AZFilter();
                break;
            case 'a':
                return new azFilter();
                break;
            case '0':
                return new zeroNineFilter();
                break;
            default:
                return nullptr;
        }
    }
};

#endif // CPP_FILTERFACTORY_H
