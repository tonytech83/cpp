//
// Created by tonytech on 11.09.2025.
//

#ifndef CPP_ARRAY_H
#define CPP_ARRAY_H
#include <vector>

template<typename T>
class Array {
    std::vector<T> _data;

public:
    explicit Array(const size_t &size) : _data(size) {}

    [[nodiscard]] auto getSize() const -> int { return this->_data.size(); }

    auto operator[](const size_t &index) -> T & { return _data[index]; }
    auto begin() -> typename std::vector<T>::iterator { return _data.begin(); }
    auto end() -> typename std::vector<T>::iterator { return _data.end(); }
};

#endif // CPP_ARRAY_H
