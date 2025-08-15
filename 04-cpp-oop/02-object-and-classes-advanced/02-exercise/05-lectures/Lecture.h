//
// Created by tonytech on 15.08.2025.
//

#ifndef CPP_LECTURE_H
#define CPP_LECTURE_H

#include <set>
#include <algorithm>

#include "Resource.h"

namespace SoftUni {

    class Lecture {
        std::set<Resource> store;


    public:
        Lecture() = default;

        auto insertResource(const Resource &newResource) -> void {
            for (auto it = this->store.begin(); it != this->store.end(); ++it)
                if (it->getId() == newResource.getId()) {
                    store.erase(it);
                    break;
                }

            store.insert(newResource);
        }

        auto begin() -> decltype(store.begin()) { return store.begin(); }

        auto end() -> decltype(store.end()) { return store.end(); }

        auto operator[](const ResourceType &rt) const -> int {
            int count = 0;
            for (auto resource: this->store)
                if (resource.getType() == rt)
                    count++;

            return count;
        }

        auto getStore() const -> std::set<Resource> { return this->store; }
    };

    inline auto operator<<(Lecture &l, const Resource &res) -> Lecture & {
        l.insertResource(res);
        return l;
    }

    inline auto operator<<(std::vector<ResourceType> &vec, const Lecture &l) -> std::vector<ResourceType> {
        std::set<ResourceType> tmp;
        for ([[maybe_unused]] auto resource: l.getStore())
            tmp.insert(resource.getType());

        for (auto rType: tmp)
            vec.push_back(rType);

        return vec;
    }

} // namespace SoftUni

#endif // CPP_LECTURE_H
