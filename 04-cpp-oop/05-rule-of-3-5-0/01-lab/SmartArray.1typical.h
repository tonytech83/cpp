//
// Created by tonytech on 30.8.2025.
//

#ifndef CPP_SMARTARRAY_1TYPICAL_H
#define CPP_SMARTARRAY_1TYPICAL_H

#include <iostream>

template<class T>
class SmartArray {
    std::size_t _size;
    T *_data;

public:
    explicit SmartArray(std::size_t size = 0) : _size(size), _data(_size ? new T[_size]{} : nullptr) {};

    ~SmartArray() { clear(); }

    // Copy
    // From this constructor we call the default constructor, the easiest way to initialize
    SmartArray(const SmartArray &other) : SmartArray() { reset(other._data, other._size); };

    auto operator=(const SmartArray &other) -> SmartArray & {
        if (this != &other) {
            reset(other._data, other._size);
        }

        return *this;
    }

    auto operator[](std::size_t index) -> T & { return _data[index]; }

    auto print() -> void {
        for (std::size_t i = 0; i < _size; i++)
            std::cout << _data[i] << ' ';

        std::cout << std::endl;
    }

private:
    auto clear() -> void {
        delete[] _data;

        _data = nullptr;
        _size = 0;
    }

    auto reset(T *newData, std::size_t size) -> void {
        T *tmpData = new T[size];
        std::copy(newData, newData + size, tmpData);

        clear();
        _data = tmpData;
        _size = size;
    }
};

#endif // CPP_SMARTARRAY_1TYPICAL_H
