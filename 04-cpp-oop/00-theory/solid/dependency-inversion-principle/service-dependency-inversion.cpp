//
// Created by tonytech on 09.09.2025.
//

#include <iostream>
using namespace std;

// Example: Application do not need to know exactly the DB, it should use interface to DB

class IService {
public:
    virtual auto performTask() -> void = 0;
    virtual ~IService() = default;
};

class Service final : public IService {
public:
    auto performTask() -> void override { cout << "Service performing task..." << endl; }
};

class ServiceOne final : public IService {
public:
    auto performTask() -> void override { cout << "ServiceOne performing task..." << endl; }
};

class Client {
    IService &m_service;

public:
    explicit Client(IService &service) : m_service(service) {}

    auto execute() const -> void { m_service.performTask(); }
};

auto main() -> int {
    Service s;
    const Client c1(s);
    c1.execute();

    ServiceOne sOne;
    const Client c2(sOne);
    c2.execute();

    return 0;
}
