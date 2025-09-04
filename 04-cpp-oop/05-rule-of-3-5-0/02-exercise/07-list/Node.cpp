//
// Created by tonytech on 04.09.2025.
//
#include "List.h"
using namespace std;

// NODE
List::Node::Node(int value, Node *prev, Node *next) : value(value), prev(prev), next(next) {}

auto List::Node::getValue() const -> int { return this->value; }
auto List::Node::setValue(int value) -> void { this->value = value; }

auto List::Node::getNext() const -> Node * { return this->next; }
auto List::Node::setNext(Node *next) -> void { this->next = next; }

auto List::Node::getPrev() const -> Node * { return this->prev; }
auto List::Node::setPrev(Node *prev) -> void { this->prev = prev; }