//
// Created by tonytech on 3.10.2025.
//

#include <iostream>

#include "VirtualBook.h"


VirtualBook::VirtualBook() = default;

auto VirtualBook::addPage(const VirtualPage &page) -> void { _pages.push_back(page); }

auto VirtualBook::printContent() const -> void {
    for (const auto &page: _pages) {
        page.printContent();
    }
}

auto VirtualBook::removeLastPage() -> void {
    if (!_pages.empty())
        _pages.pop_back();
}

auto VirtualBook::removeAllPages() -> void {
    if (!_pages.empty())
        _pages.clear();
}
