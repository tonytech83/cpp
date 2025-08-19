//
// Created by tonytech on 19.08.2025.
//

#ifndef CPP_FILEWRITER_H
#define CPP_FILEWRITER_H

class Employee;
class Management;

class FileWriter {
    static auto SaveEmployee(const Employee &e) -> void;

public:
    FileWriter() = default;
    static auto SaveToFile(const Management &m) -> void;
};

#endif // CPP_FILEWRITER_H
