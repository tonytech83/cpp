#include <iostream>
#include <sstream>
#include <string>

#include "CommandInterface.h"
#include "Initialization.h"


int main() {
    std::string text;
    std::getline(std::cin, text);

    std::shared_ptr<CommandInterface> interface = buildCommandInterface(text);

    std::string inputLine;
    std::getline(std::cin, inputLine);
    while (inputLine != "exit") {
        interface->handleInput(inputLine);
        std::getline(std::cin, inputLine);
    }

    std::cout << text << std::endl;

    return 0;
}
