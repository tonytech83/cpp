//
// Created by tonytech on 30.8.2025.
//

#ifndef CPP_SMARTARRAY_3COPYSWAP_H
#define CPP_SMARTARRAY_3COPYSWAP_H

#include <algorithm>

template<typename T>
class SmartArray {

public:
    class Iterator {

        SmartArray &data;
        size_t index;

    public:
        Iterator(SmartArray &data, size_t index) : data(data), index(index) {}

        bool operator!=(const Iterator &other) const {
            if (data._data != other.data._data)
                return true;

            if (index >= data._size && other.index >= other.data._size)
                return false; // both are "end()"

            if (index == other.index)
                return false; // both are equal

            return true;
        }

        Iterator &operator++() {
            index++;
            return *this;
        }

        T &operator*() {
            if (index >= data._size)
                throw std::out_of_range("out of range.");
            return data[index];
        }
    };

    Iterator begin() { return Iterator(*this, 0); }

    Iterator end() { return Iterator(*this, SIZE_T_MAX); }

    SmartArray(size_t size = 0) : _size(size), _data(_size ? new T[_size]{} : nullptr) {}

    ~SmartArray() { clear(); }

    SmartArray(const SmartArray &other) : SmartArray() { reset(other._data, other._size); }

    SmartArray &operator=(SmartArray other) {
        swap(*this, other);
        return *this;
    }

    T &operator[](size_t index) { return _data[index]; }

    void print() const {
        for (size_t i = 0; i < _size; ++i) {
            std::cout << _data[i] << ' ';
        }
        std::cout << std::endl;
    }

    void resize(size_t newSize) {
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

    void reset(T *newData, size_t size) {
        T *tmpData = new T[size]{0};
        std::copy(newData, newData + size, tmpData);

        clear();
        _data = tmpData;
        _size = size;
    }

    friend void swap(SmartArray &a, SmartArray &b) {
        std::swap(a._data, b._data);
        std::swap(a._size, b._size);
    }

private:
    size_t _size;
    T *_data;

    void clear() {
        if (_data != nullptr)
            delete[] _data;
        _data = nullptr;
        _size = 0;
    }
};

#endif // CPP_SMARTARRAY_3COPYSWAP_H
