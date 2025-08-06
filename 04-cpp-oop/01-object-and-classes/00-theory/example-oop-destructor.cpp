//
// Created by tonytech on 06.08.2025.
//

#include <iostream>
using namespace std;

class IntList {
    int numElements;
    int *arr;

public:
    explicit IntList(const int numElements) {
        this->numElements = numElements;
        this->arr = new int[numElements]; // we have memory leak here if no Destructor
    }

    // Copy constructor
    IntList(const IntList &other) {
        delete[] this->arr;
        this->numElements = other.numElements;
        this->arr = new int[other.numElements];
        for (int i = 0; i < numElements; i++) {
            this->arr[i] = other.arr[i];
        }
    }

    auto setElement(const int index, const int value) const -> void { this->arr[index] = value; }

    [[nodiscard]] auto getElement(const int index) const -> int { return this->arr[index]; }

    [[nodiscard]] auto getSize() const -> int { return this->numElements; }

    // Destructor
    ~IntList() { delete[] this->arr; }

    // Copy assigment operator
    IntList &operator=(const IntList &other) {
        if (this != &other) {
            delete[] this->arr;
            this->numElements = other.numElements;
            this->arr = new int[other.numElements];
            for (int i = 0; i < numElements; i++) {
                this->arr[i] = other.arr[i];
            }
        }
        return *this;
    }
};


auto main() -> int {
    IntList first(5);

    {
        const IntList second(2);
        second.setElement(0, 10);
        second.setElement(1, 20);

        first = second;
    }

    cout << first.getElement(1) << endl;

    return 0;

    // while (true) {
    //     const IntList l(5);
    //     l.setElement(0, 1);
    //     cout << l.getElement(0) << endl;
    //     cout << l.getSize() << endl;
    // }
}
