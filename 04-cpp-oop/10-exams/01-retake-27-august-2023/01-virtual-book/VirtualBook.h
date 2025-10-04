//
// Created by tonytech on 3.10.2025.
//

#ifndef CPP_VIRTUALBOOK_H
#define CPP_VIRTUALBOOK_H

#include "VirtualPage.h"


class VirtualBook {
    std::vector<VirtualPage> _pages;

public:
    VirtualBook();

    auto addPage(const VirtualPage &page) -> void;

    auto printContent() const -> void;

    auto removeLastPage() -> void;

    auto removeAllPages() -> void;
};


#endif // CPP_VIRTUALBOOK_H
