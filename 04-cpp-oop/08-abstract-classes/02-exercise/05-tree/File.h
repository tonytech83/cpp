//
// Created by tonytech on 29.9.2025.
//

#ifndef CPP_FILE_H
#define CPP_FILE_H

#include <string>

#include "ByteContainer.h"
#include "FileSystemObject.h"

class File final : public FileSystemObject, public ByteContainer {
    std::string bytes;

public:
    explicit File(const std::string &filename, const std::string &bytes) : FileSystemObject(filename), bytes(bytes) {}

    [[nodiscard]] auto getBytes() const -> std::string override { return bytes; }

    [[nodiscard]] auto getSize() const -> size_t override { return this->bytes.size(); };
};

#endif // CPP_FILE_H
