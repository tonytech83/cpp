//
// Created by tonytech on 30.9.2025.
//

#ifndef CPP_COMPANY_H
#define CPP_COMPANY_H

#include <sstream>
#include <vector>

struct HasInfo {
    virtual auto getInfo() const -> std::string = 0;

    virtual ~HasInfo() = default;
};

struct HasId {
    virtual auto getId() const -> int = 0;

    virtual ~HasId() = default;
};

class Company : public HasInfo, public HasId {
    int id;
    std::string name;
    std::vector<std::pair<char, char>> employees;

public:
    Company();
    Company(int id, std::string name, std::vector<std::pair<char, char>> employees);

    auto getId() const -> int override;

    auto getName() const -> std::string;

    auto getEmployees() const -> std::vector<std::pair<char, char>>;

    auto getInfo() const -> std::string override;

    friend auto operator<<(std::ostream &stream, const Company &c) -> std::ostream &;

    friend auto operator>>(std::istream &stream, Company &c) -> std::istream &;
};

#endif // CPP_COMPANY_H
