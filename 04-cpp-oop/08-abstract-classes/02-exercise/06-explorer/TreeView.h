//
// Created by tonytech on 29.9.2025.
//

#ifndef CPP_TREEVIEW_H
#define CPP_TREEVIEW_H

#include <algorithm>
#include <sstream>
#include <vector>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"

inline auto getTreeView(const std::vector<std::shared_ptr<FileSystemObject>>::const_iterator begin,
                        const std::vector<std::shared_ptr<FileSystemObject>>::const_iterator end,
                        const std::string &indentation) -> std::string {
    std::ostringstream oss;

    std::vector<std::shared_ptr<FileSystemObject>> sortedObjects;
    std::copy(begin, end, std::back_inserter(sortedObjects));

    std::sort(sortedObjects.begin(), sortedObjects.end(),
              [](const std::shared_ptr<FileSystemObject> &a, const std::shared_ptr<FileSystemObject> &b) {
                  return a->getName() < b->getName();
              });
    for (const auto &o: sortedObjects) {
        oss << indentation << o->getName() << std::endl;

        auto *container = dynamic_cast<FileSystemObjectsContainer *>(o.get());
        // the current FileObject is directory
        if (container != nullptr)
            oss << getTreeView(container->begin(), container->end(), indentation + "--->");
    }

    return oss.str();
}

inline auto getTreeView(const std::vector<std::shared_ptr<FileSystemObject>> &rootObjects) -> std::string {
    return getTreeView(rootObjects.begin(), rootObjects.end(), "");
}

#endif // CPP_TREEVIEW_H
