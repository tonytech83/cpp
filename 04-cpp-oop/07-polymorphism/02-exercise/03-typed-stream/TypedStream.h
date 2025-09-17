//
// Created by tonytech on 17.09.2025.
//

#ifndef CPP_TYPEDSTREAM_H
#define CPP_TYPEDSTREAM_H

#include <sstream>
#include <vector>

template<class T>
class TypedStream {
protected:
    std::istringstream stream;

public:
    explicit TypedStream(const std::string &input) : stream(input) {}

    virtual TypedStream<T> &operator>>(T &i) = 0;

    auto readToEnd() -> std::vector<T> {
        std::vector<T> result;

        T token;
        while (true) {
            *this >> token;
            if (static_cast<bool>(stream) == false)
                break;

            result.emplace_back(token);
        }
        return result;
    }

    virtual ~TypedStream() = default;
};

#endif // CPP_TYPEDSTREAM_H
