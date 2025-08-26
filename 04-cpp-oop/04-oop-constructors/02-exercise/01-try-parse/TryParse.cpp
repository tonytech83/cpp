//
// Created by tonytech on 26.08.2025.
//
#include "TryParse.h"

#include <sstream>
using namespace std;

class TryParse {
    istringstream iss;

public:
    TryParse(const string &str, int &number) : iss(str) {
        // try to read iss to number, return false if can not
        iss >> number;
    }

    // Type conversion
    operator bool() const { return static_cast<bool>(iss); }
};

auto tryParse(const string &str, int &number) -> bool {
    TryParse parser(str, number);

    return parser;
}
