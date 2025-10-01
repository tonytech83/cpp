//
// Created by tonytech on 1.10.2025.
//

#ifndef CPP_STORE_H
#define CPP_STORE_H

#include <algorithm>
#include <iostream>
#include <memory>

#include "Defines.h"
#include "PSConsole.h"
#include "XboxConsole.h"

class Store {
    std::vector<std::unique_ptr<PSConsole>> ps;
    std::vector<std::unique_ptr<XboxConsole>> xbox;

    template<class T>
    auto printConsoles(const std::vector<std::unique_ptr<T>> &consoles, const std::string &label) const -> void {
        std::cout << "Printing all " << label << " data" << std::endl;
        for (const auto &c: consoles) {
            c->showPrint();
        }
    }

public:
    Store() = default;

    auto addPs(const int &price, const int &quality, const int &generation) -> void {
        auto newPs = std::make_unique<PSConsole>(price, quality, generation);

        std::cout << "Adding: ";
        newPs->showPrint();

        ps.push_back(std::move(newPs));
    }

    auto addXbox(const int &price, const int &quality) -> void {
        auto newXbox = std::make_unique<XboxConsole>(price, quality);

        std::cout << "Adding: ";
        newXbox->showPrint();

        xbox.push_back(std::move(newXbox));
    }

    auto remove(ConsoleType consoleType) -> void {
        if (consoleType == ConsoleType::PS) {
            std::cout << "Removing: ";
            ps.back()->showPrint();
            ps.pop_back();
        } else {
            std::cout << "Removing: ";
            xbox.back()->showPrint();
            xbox.pop_back();
        }
    }

    auto sortByPrice(ConsoleType consoleType) -> void {
        std::cout << "Sorting all " << (consoleType == ConsoleType::PS ? "PS" : "Xbox") << " by price" << std::endl;

        if (consoleType == ConsoleType::PS)
            std::sort(ps.begin(), ps.end(), [](const auto &a, const auto &b) { return a->getPrice() > b->getPrice(); });
        else
            std::sort(xbox.begin(), xbox.end(),
                      [](const auto &a, const auto &b) { return a->getPrice() > b->getPrice(); });
    }

    auto sortByQuality(ConsoleType consoleType) -> void {
        std::cout << "Sorting all " << (consoleType == ConsoleType::PS ? "PS" : "Xbox") << " by quality " << std::endl;

        if (consoleType == ConsoleType::PS)
            std::sort(ps.begin(), ps.end(),
                      [](const auto &a, const auto &b) { return a->getQuality() > b->getQuality(); });

        else
            std::sort(xbox.begin(), xbox.end(),
                      [](const auto &a, const auto &b) { return a->getQuality() > b->getQuality(); });
    }

    auto print(ConsoleType consoleType) const -> void {
        if (consoleType == ConsoleType::PS) {
            printConsoles(ps, "PS");
        } else {
            printConsoles(xbox, "Xbox");
        }
    }
};

#endif // CPP_STORE_H
