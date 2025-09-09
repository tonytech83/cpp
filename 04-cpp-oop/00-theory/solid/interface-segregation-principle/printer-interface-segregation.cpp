//
// Created by tonytech on 09.09.2025.
//
#include <iostream>
using namespace std;

// Interface class
class Printer {
public:
    virtual auto print(const string &document) -> void = 0;

    virtual ~Printer() = default;
};

class Scanner {
public:
    virtual auto scan(const string &document) -> void = 0;

    virtual ~Scanner() = default;
};

class Fax {
public:
    virtual auto fax(const string &document) -> void = 0;

    virtual ~Fax() = default;
};

class MultifunctionPrinter final : public Printer, public Scanner, public Fax {
public:
    auto print(const string &document) -> void override { cout << "print" << endl; }
    auto scan(const string &document) -> void override { cout << "scan" << endl; }
    auto fax(const string &document) -> void override { cout << "fax" << endl; }

    ~MultifunctionPrinter() override { cout << "~MultifunctionPrinter" << endl; }
};

class SimplePrinter final : public Printer {
public:
    auto print(const string &document) -> void override { cout << "print" << endl; }

    ~SimplePrinter() override { cout << "~SimplePrinter" << endl; }
};


auto main() -> int {
    auto mPrinter = new MultifunctionPrinter();
    mPrinter->print("Hello");

    auto sPrinter = new SimplePrinter();
    sPrinter->print("Hello");

    return 0;
}
