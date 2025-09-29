//
// Created by tonytech on 29.9.2025.
//

#ifndef CPP_DIRECTORY_H
#define CPP_DIRECTORY_H

#include <list>
#include <string>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"

class Directory final : public FileSystemObject, public FileSystemObjectsContainer {
    std::list<std::shared_ptr<FileSystemObject>> container;

public:
    explicit Directory(const std::string &name) : FileSystemObject(name) {}

    [[nodiscard]] auto getSize() const -> size_t override {
        size_t dirSize = 0;
        for (const auto &o: container)
            dirSize += o->getSize();

        return dirSize;
    };

    auto add(const std::shared_ptr<FileSystemObject> &obj) -> void override { container.push_back(obj); }
};

#endif // CPP_DIRECTORY_H
