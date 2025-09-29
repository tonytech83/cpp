#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "Extractor.h"
#include "ExtractorInitialization.h"

int main() {
    std::string line;

    std::getline(std::cin, line);

    std::istringstream lineIn(line);

    std::string extractType;
    std::cin >> extractType;
    std::shared_ptr<Extractor> s = getExtractor(extractType, lineIn);

    std::vector<std::string> extracted = s->extractAll();

    for (auto item: extracted) {
        std::cout << item << std::endl;
    }

    return 0;
}
