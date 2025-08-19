//
// Created by tonytech on 19.08.2025.
//
#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted) : copyrighted(std::move(copyrighted)) {}

auto Article13Filter::blockIfCopyrighted(std::string s) -> bool {
    if (isCopyrighted(s)) {
        blocked.push_back(s);
        return true;
    }

    return false;
}

auto Article13Filter::isCopyrighted(std::string s) -> bool { return !copyrighted.insert(s).second; }

auto Article13Filter::getBlocked() -> std::vector<std::string> { return blocked; }
