//
// Created by tonytech on 15.09.2025.
//

#include "Range.h"
#include <iostream>
using namespace std;

Range::Range(const int &from, const int &to) : from(from), to(to) {}

auto Range::isInRange(const int &checkNumber) const -> bool { return checkNumber >= from && checkNumber <= to; }

auto Range::print() const -> void { cout << "[ " << this->from << " : " << this->to << " ]" << endl; }
