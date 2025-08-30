//
// Created by tonytech on 30.8.2025.
//

#ifndef CPP_SMARTARRAY_2RULE5_H
#define CPP_SMARTARRAY_2RULE5_H

#include <algorithm>

template<class T>
class SmartArray {
    std::size_t _size;
    T *_data;

public:
    class Iterator {
        SmartArray &data;
        size_t index;

    public:
        Iterator(SmartArray &data, size_t index) : data(data), index(index) {}

        auto operator!=(const Iterator &other) const -> bool {
            if (this->data._data != other.data._data)
                return true;

            if (this->index != data._size && other.index > other.data._size)
                return true; // both are end

            if (this->index == other.index)
                return false; // both are equal

            return true;
        }

        auto operator++() -> Iterator & {
            index++;
            return *this;
        }

        // Return reference to current index
        auto operator*() -> T & {
            if (index >= data._size)
                throw std::out_of_range("out of range");
            return data[index];
        }
    };

    auto begin() -> Iterator { return Iterator(*this, 0); }

    auto end() -> Iterator { return Iterator(*this, SIZE_T_MAX); }

    // Default initialzation
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

    auto resize(std::size_t newSize) -> void {
        T *tmpData;
        if (newSize)
            tmpData = new T[newSize]{0};
        else
            tmpData = nullptr;

        if (_data != nullptr && tmpData != nullptr)
            std::copy(_data, _data + std::min(newSize, _size), tmpData);

        clear();
        _data = tmpData;
        _size = newSize;
    }

    auto reset(T *newData, std::size_t size) -> void {
        T *tmpData = new T[size];
        std::copy(newData, newData + size, tmpData);

        clear();
        _data = tmpData;
        _size = size;
    }

    auto friend swap(SmartArray &a, SmartArray &b) -> void {
        std::swap(a._data, b._data);
        std::swap(a._size, b._size);
    }

private:
    auto clear() -> void {
        delete[] _data;

        _data = nullptr;
        _size = 0;
    }
};

#endif // CPP_SMARTARRAY_2RULE5_H
