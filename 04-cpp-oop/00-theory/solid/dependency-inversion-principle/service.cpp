//
// Created by tonytech on 09.09.2025.
//
#include <iostream>
using namespace std;

class Service {
public:
     auto performTask() -> void { cout << "Performing task..." << endl; }
};

// We can not add new class for example ServiceOne
// Also this new class may have different method

class Client {
    Service &m_service;

public:
    explicit Client(Service &service) : m_service(service) {}

    auto execute() const -> void { m_service.performTask(); }
};

auto main() -> int {
    Service s;
    Client c(s);
    c.execute();

    return 0;
}
