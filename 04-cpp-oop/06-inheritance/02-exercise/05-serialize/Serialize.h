//
// Created by tonytech on 11.09.2025.
//

#ifndef CPP_SERIALIZE_H
#define CPP_SERIALIZE_H

#include <iostream>
#include <sstream>


#include "Company.h"

class SerializeCompany : public Company {
public:
    auto serializeToMemory(std::vector<byte> &memory) const -> size_t {
        return serializeId(memory) + serializeName(memory) + serializeEmployees(memory);
    }

protected:
    auto serializeId(std::vector<byte> &memory) const -> size_t {
        memory.push_back(this->getId());
        return 1;
    }
    auto serializeName(std::vector<byte> &memory) const -> size_t {
        const std::string name = this->getName();
        for (const char &ch: name)
            memory.push_back(ch);

        memory.push_back(0); // zero after name

        return name.length() + 1; // written the length of name + 1 for zero
    }
    auto serializeEmployees(std::vector<byte> &memory) const -> size_t {
        const std::vector<std::pair<char, char>> employees = this->getEmployees();
        memory.push_back(employees.size()); // the count of employees

        for (const auto &[fst, snd]: employees) {
            memory.push_back(fst);
            memory.push_back(snd);
        }

        return 1 + employees.size() * 2; // 1 is byte where is stored the count of employees
    }
};

inline auto serializeToMemory(const std::string &input, size_t &bytesWritten) -> byte * {
    std::istringstream iss(input);
    std::vector<byte> output(1, 0); // keep the first byte for companies count
    bytesWritten = 1; // companies byte count

    SerializeCompany company;
    while (iss >> company) {
        output[0]++; // increase the number ot the companies read in first byte
        bytesWritten += company.serializeToMemory(output); // increase the written bytes with size ot current company
    }

    const auto returnBuffer = new byte[output.size()];
    std::copy(output.begin(), output.end(), returnBuffer);

    return returnBuffer;
}

#endif // CPP_SERIALIZE_H
