//
// Created by tonytech on 30.8.2025.
//

#ifndef CPP_SMARTARRAY_4RULE0_H
#define CPP_SMARTARRAY_4RULE0_H

#include <algorithm>
#include <vector>

template<typename T>
class SmartArray {
    std::vector<T> _data;

public:
    explicit SmartArray(size_t size = 0) : _data(size) {}

    auto operator[](size_t index) -> T & { return _data[index]; }

    auto print() const -> void {
        for (const T &d: _data) {
            std::cout << d << ' ';
        }
        std::cout << std::endl;
    }

    auto begin() -> typename std::vector<T>::iterator { return _data.begin(); }
    auto end() -> typename std::vector<T>::iterator { return _data.end(); }

    auto resize(size_t newSize) -> void { _data.resize(newSize); }

    auto reset(T *newData, size_t size) -> void {
        _data.resize(size);
        std::copy(newData, newData + size, _data.begin());
    }

    friend auto swap(SmartArray &a, SmartArray &b) -> void { std::swap(a._data, b._data); }
};

#endif // CPP_SMARTARRAY_4RULE0_H
