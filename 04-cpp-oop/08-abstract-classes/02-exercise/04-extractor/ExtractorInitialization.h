//
// Created by tonytech on 29.9.2025.
//

#ifndef CPP_EXTRACTORINITIALIZATION_H
#define CPP_EXTRACTORINITIALIZATION_H

#include <memory>
#include <string>

#include "BufferedExtractor.h"

class DigitsExtractor final : public Extractor {
public:
    explicit DigitsExtractor(std::istream &stream) : Extractor(stream) {}

protected:
    auto process(const char symbol, std::string &output) -> bool override {
        if (std::isdigit(symbol)) {
            output.append(1, symbol);
            return true;
        }
        return false;
    }
};

class NumbersExtractor final : public BufferedExtractor {
public:
    explicit NumbersExtractor(std::istream &stream) : BufferedExtractor(stream) {}

protected:
    auto shouldBuffer(const char symbol) -> bool override { return std::isdigit(symbol); }
};

class QuotesExtractor final : public BufferedExtractor {
    bool inQuotes = false;

public:
    explicit QuotesExtractor(std::istream &stream) : BufferedExtractor(stream) {}

protected:
    auto shouldBuffer(const char symbol) -> bool override {
        if (symbol == '"') {
            inQuotes = !inQuotes;
            return false;
        }
        return inQuotes;
    }
};


auto getExtractor(const std::string &extractType, std::istringstream &lineIn) -> std::shared_ptr<Extractor> {
    if (extractType == "digits") {
        return std::make_shared<DigitsExtractor>(lineIn);
    } else if (extractType == "numbers") {
        return std::make_shared<NumbersExtractor>(lineIn);
    } else
        return std::make_shared<QuotesExtractor>(lineIn);
}

#endif // CPP_EXTRACTORINITIALIZATION_H
