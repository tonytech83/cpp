//
// Created by tonytech on 17.09.2025.
//

#ifndef CPP_AVERAGEAGGREGATOR_H
#define CPP_AVERAGEAGGREGATOR_H

#endif // CPP_AVERAGEAGGREGATOR_H

#include "Aggregator.h"

class AverageAggregator final : public StreamAggregator {
    int sum;

public:
    explicit AverageAggregator(std::istream &stream) : StreamAggregator(stream), sum(0) {
        aggregationResult = 0;
    }

protected:
    auto aggregate(const int next) -> void override {
        StreamAggregator::aggregate(next); // should execute Base class aggregate method to count aggregated numbers
        sum += next;
        aggregationResult = sum / getNumAggregated();
    }
};
