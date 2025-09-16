//
// Created by tonytech on 16.09.2025.
//

#ifndef CPP_INITIALIZATION_H
#define CPP_INITIALIZATION_H

#include <memory>
#include "CommandInterface.h"

class AdvancedCommandInterface final : public CommandInterface {
    std::string clipboard;

    class cutTransform final : public TextTransform {
        std::string &clipboard;

    public:
        explicit cutTransform(std::string &clipboard) : TextTransform(), clipboard(clipboard) {}

        auto invokeOn(std::string &text, const int startIndex, const int endIndex) -> void override {
            this->clipboard = text.substr(startIndex, endIndex - startIndex);
            text.erase(startIndex, endIndex - startIndex);
        }
    };

    class pasteTransform final : public TextTransform {
        std::string &clipboard;

    public:
        explicit pasteTransform(std::string &clipboard) : TextTransform(), clipboard(clipboard) {}

        auto invokeOn(std::string &text, const int startIndex, const int endIndex) -> void override {
            const auto itStart = text.begin() + startIndex;
            const auto itEnd = text.begin() + endIndex;

            text.replace(itStart, itEnd, clipboard);
        }
    };

public:
    explicit AdvancedCommandInterface(std::string &text) : CommandInterface(text) {}

protected:
    auto initCommands() -> std::vector<Command> override {
        std::vector<Command> commands = CommandInterface::initCommands();

        // commands.push_back(Command("uppercase", std::make_shared<ToUpperTransform>()));
        commands.emplace_back("cut", std::make_shared<cutTransform>(clipboard));
        commands.emplace_back("paste", std::make_shared<pasteTransform>(clipboard));

        return commands;
    }
};

inline auto buildCommandInterface(std::string &text) -> std::shared_ptr<CommandInterface> {
    std::shared_ptr<CommandInterface> CI(new AdvancedCommandInterface(text));
    CI->init();

    return CI;
}

#endif // CPP_INITIALIZATION_H
