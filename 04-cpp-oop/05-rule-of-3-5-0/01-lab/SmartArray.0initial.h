//
// Created by tonytech on 30.8.2025.
//

#ifndef CPP_SMARTARRAY_0INITIAL_H
#define CPP_SMARTARRAY_0INITIAL_H

#include <iostream>

template<class T>
class SmartArray {
    std::size_t _size;
    T *_data;

public:
    explicit SmartArray(std::size_t size) : _size(size), _data(_size ? new T[_size]{} : nullptr) {};

    ~SmartArray() { delete[] _data; }

    // Delete both default
    SmartArray (const SmartArray &) = delete;
    auto operator=(const SmartArray &) -> SmartArray & = delete;

    auto operator[](std::size_t index) -> T & { return _data[index]; }

    auto print() -> void {
        for (std::size_t i = 0; i < _size; i++)
            std::cout << _data[i] << ' ';

        std::cout << std::endl;
    }
};

#endif // CPP_SMARTARRAY_0INITIAL_H
