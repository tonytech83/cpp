//
// Created by tonytech on 29.9.2025.
//

#ifndef CPP_BYTECONTAINER_H
#define CPP_BYTECONTAINER_H

#include <string>

struct ByteContainer {

    [[nodiscard]] virtual auto getBytes() const -> std::string = 0;

    virtual ~ByteContainer() = default;
};

#endif // CPP_BYTECONTAINER_H
