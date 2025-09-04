//
// Created by tonytech on 04.09.2025.
//
#include "List.h"
#include <sstream>
using namespace std;

// LIST
List::List() : head(nullptr), tail(nullptr), size(0) {}
List::List(const List &other) : List() { this->addAll(other); }

auto List::first() const -> int {
    if (this->isEmpty())
        return 0;

    return this->head->getValue();
}
auto List::add(int value) -> void {
    auto *newNode = new Node(value, nullptr, nullptr);

    if (tail == nullptr && head == nullptr) {
        // size will be 0 => empty list
        this->head = this->tail = newNode;
    } else {
        // tail points to our last element
        this->tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    this->size++;
}
auto List::addAll(const List &other) -> void {
    // Blind add `other` list element, it does not re-sort them!
    const Node *current = other.head;
    while (current != nullptr) {
        add(current->getValue());
        current = current->getNext();
    }
}
auto List::removeFirst() -> void {
    if (this->isEmpty())
        return;

    if (this->size == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    } else {
        const auto *currHead = this->head; // take current head as variable
        this->head = currHead->getNext(); // set head to current head next node
        this->head->setPrev(nullptr); // set head previous to nullptr (no prev element)
        delete currHead; // delete old head node
    }

    this->size--;
}
auto List::removeAll() -> void {
    this->head = this->tail = nullptr;
    this->size = 0;
}

auto List::getSize() const -> size_t { return size; }
auto List::isEmpty() const -> bool { return size == 0; }

auto List::getReversed(List l) -> List {
    if (l.isEmpty())
        return l;

    List reversed;

    const Node *current = l.tail;
    while (current != nullptr) {
        reversed.add(current->getValue());
        current = current->getPrev();
    }

    return reversed;
}
auto List::toString() const -> string {
    ostringstream oss;

    const Node *current = this->head;
    while (current != nullptr) {
        oss << current->getValue() << ' ';
        current = current->getNext();
    }

    return oss.str();
}

auto List::operator<<(const int &value) -> List & {
    this->add(value);
    return *this;
}

auto List::operator<<(const List &other) -> List & {
    this->addAll(other);
    return *this;
}

auto List::operator=(const List &other) -> List & {
    if (this == &other)
        return *this;

    removeAll();
    addAll(other);

    return *this;
}

List::~List() { removeAll(); }
