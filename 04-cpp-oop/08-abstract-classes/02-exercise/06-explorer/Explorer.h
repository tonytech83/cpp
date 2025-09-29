//
// Created by tonytech on 29.9.2025.
//

#ifndef CPP_EXPLORER_H
#define CPP_EXPLORER_H

#include <algorithm>
#include <memory>
#include <vector>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"
#include "Shortcuts.h"

class Root final : public FileSystemObjectsContainer, public FileSystemObject {
    std::vector<std::shared_ptr<FileSystemObject>> &objects;

public:
    Root(const std::string &name, std::vector<std::shared_ptr<FileSystemObject>> &rootObjects) :
        FileSystemObject(name), objects(rootObjects) {}

    auto add(const std::shared_ptr<FileSystemObject> &obj) -> void override { this->objects.push_back(obj); }

    auto begin() const -> std::vector<std::shared_ptr<FileSystemObject>>::const_iterator override {
        return this->objects.begin();
    }

    auto end() const -> std::vector<std::shared_ptr<FileSystemObject>>::const_iterator override {
        return this->objects.end();
    }

    auto setParent(const std::weak_ptr<FileSystemObject> &parent) -> void override {
        // do nothing, because root does not have a parent
    }

    auto getParent() const -> std::weak_ptr<FileSystemObject> override {
        // returns empty weak_ptr, because root has no parent
        return std::weak_ptr<FileSystemObject>();
    }

    auto remove(const std::shared_ptr<FileSystemObject> obj) -> void override {
        const auto idx = std::find(objects.begin(), objects.end(), obj);
        this->objects.erase(idx);
    }

    auto getSize() const -> size_t override { return 0; }
};

class Explorer {
    std::shared_ptr<Root> root;
    std::shared_ptr<FileSystemObjectsContainer> currDirectory;
    std::shared_ptr<Shortcuts> shortcuts;
    std::vector<std::shared_ptr<FileSystemObject>> clipboard;

public:
    explicit Explorer(std::vector<std::shared_ptr<FileSystemObject>> &rootObjects) :
        root(std::make_shared<Root>("", rootObjects)), currDirectory(root) {}

    auto createFile(const std::string &filename, const std::string &contents) const -> void {
        // create a file
        const auto file = std::make_shared<File>(filename, contents);
        // add file in current directory
        this->currDirectory->add(file);
        // set file parent to current directory
        // we are using `dynamic_pointer_cast` because should pass from interface pointer to FileSystemObject pointer
        file->setParent(std::dynamic_pointer_cast<FileSystemObject>(this->currDirectory));
    }

    auto createDirectory(const std::string &name) const -> void {
        const auto dir = std::make_shared<Directory>(name);
        this->currDirectory->add(dir);
        dir->setParent(std::dynamic_pointer_cast<FileSystemObject>(this->currDirectory));
    }

    auto cut(const std::string &name) -> void {
        const auto ojb = find(name);
        clipboard.push_back(ojb);
    }

    auto paste() -> void {
        if (!clipboard.empty())
            for (auto &obj: clipboard)
                moveTo(obj, this->currDirectory);

        this->clipboard.clear();
    }

    auto createShortcut(const std::string &name) -> void {
        if (!this->shortcuts) {
            this->shortcuts = std::make_shared<Shortcuts>();
            this->root->add(this->shortcuts);
        }
        shortcuts->add(find(name));
    }


    auto navigate(const std::string &path) -> void {
        std::vector<std::string> paths = getPathParts(path);
        navigate(paths);
    }

protected:
    static auto findIn(const std::shared_ptr<FileSystemObjectsContainer> &dir, const std::string &name)
            -> std::shared_ptr<FileSystemObject> {
        for (const auto &ojb: *dir)
            if (ojb->getName() == name)
                return ojb;

        return nullptr;
    }

    auto find(const std::string &name) const -> std::shared_ptr<FileSystemObject> {
        return findIn(this->currDirectory, name);
    }

    auto moveTo(const std::shared_ptr<FileSystemObject> &obj,
                const std::shared_ptr<FileSystemObjectsContainer> &currDir) const -> void {
        auto previousParent = std::dynamic_pointer_cast<FileSystemObjectsContainer>(obj->getParent().lock());

        if (previousParent)
            previousParent->remove(obj);
        else
            root->add(obj);

        currDir->add(obj);
        if (currDir != this->root)
            obj->setParent(std::dynamic_pointer_cast<FileSystemObject>(currDir));
    }

    static auto getPathParts(const std::string &path) -> std::vector<std::string> {
        std::vector<std::string> parts;

        std::istringstream pathIn(path);
        std::string part;
        while (std::getline(pathIn, part, '/'))
            parts.push_back(part);

        return parts;
    }

    auto navigateSingleStep(std::string path) -> bool {
        if (path == "..") {
            auto currentAsFso = std::dynamic_pointer_cast<FileSystemObject>(this->currDirectory);

            std::shared_ptr<FileSystemObject> parentPtr =
                    (currentAsFso ? currentAsFso->getParent().lock() : std::shared_ptr<FileSystemObject>());

            if (parentPtr) {
                this->currDirectory = std::dynamic_pointer_cast<FileSystemObjectsContainer>(parentPtr);
            } else {
                auto asRoot = std::dynamic_pointer_cast<Root>(this->currDirectory);
                this->currDirectory = this->root;
                return true;
            }

            return false;
        }
        const auto fso = this->findIn(this->currDirectory, path);

        auto nestedDir = std::dynamic_pointer_cast<FileSystemObjectsContainer>(fso);
        if (nestedDir) {
            this->currDirectory = nestedDir;
            return true;
        }

        return false;
    }

    auto navigate(std::vector<std::string> paths) -> void {
        for (auto idx = paths.begin(); idx != paths.end(); idx++)
            this->navigateSingleStep(*idx);
    }
};

#endif // CPP_EXPLORER_H
