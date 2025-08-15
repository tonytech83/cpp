//
// Created by tonytech on 15.08.2025.
//

#ifndef CPP_RESOURCE_H
#define CPP_RESOURCE_H

#include <iostream>
#include <string>
#include "ResourceType.h"

namespace SoftUni {

    class Resource {
        int id = 0;
        ResourceType type;
        std::string link;

    public:
        Resource() = default;

        Resource(const int &id, const ResourceType &type, const std::string &link) : id(id), type(type), link(link) {}

        auto operator<(const Resource &other) const -> bool { return this->id < other.id; }

        auto getType() const -> ResourceType { return this->type; }

        auto getLink() const -> std::string { return this->link; }

        auto getId() const -> int { return this->id; }
    };

    inline auto operator>>(std::istream &is, ResourceType &rt) -> std::istream & {
        /// Create operator overload for ResourceType
        std::string strType;
        is >> strType;

        if (strType == "Demo")
            rt = DEMO;
        else if (strType == "Video")
            rt = VIDEO;
        else if (strType == "Presentation")
            rt = PRESENTATION;

        return is;
    }

    inline auto operator>>(std::istream &is, Resource &res) -> std::istream & {
        int id;
        ResourceType type;
        std::string link;
        is >> id;
        is >> type; // using custom operator overload, because compilator don't know how to manage `>>` for ResourceType
        is >> link;

        res = Resource(id, type, link);
        return is;
    }

    inline auto operator<<(std::ostream &os, const Resource &res) -> std::ostream & {
        os << res.getId() << ' ' << res.getType() << ' ' << res.getLink();
        return os;
    }


} // namespace SoftUni
#endif // CPP_RESOURCE_H
