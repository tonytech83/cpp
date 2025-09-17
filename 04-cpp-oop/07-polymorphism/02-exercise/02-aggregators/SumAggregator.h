//
// Created by tonytech on 17.09.2025.
//

#ifndef CPP_SUMAGGREGATOR_H
#define CPP_SUMAGGREGATOR_H

#include "Aggregator.h"

class SumAggregator final : public StreamAggregator {

public:
    explicit SumAggregator(std::istream &stream) : StreamAggregator(stream) { aggregationResult = 0; }

protected:
    auto aggregate(int next) -> void override {
        aggregationResult += next;
    }
};

#endif // CPP_SUMAGGREGATOR_H
