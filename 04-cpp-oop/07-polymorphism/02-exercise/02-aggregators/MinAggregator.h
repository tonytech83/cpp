//
// Created by tonytech on 17.09.2025.
//

#ifndef CPP_MINAGGREGATOR_H
#define CPP_MINAGGREGATOR_H

#endif // CPP_MINAGGREGATOR_H

#include <climits>
#include "Aggregator.h"

class MinAggregator final : public StreamAggregator {
    // std::istream &stream;

public:
    explicit MinAggregator(std::istream &stream) : StreamAggregator(stream) { aggregationResult = INT_MAX; }

protected:
    auto aggregate(int next) -> void override {
        if (next < aggregationResult)
            aggregationResult = next;
    }
};
