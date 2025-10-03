//
// Created by tonytech on 3.10.2025.
//

#include "classes.h"
#include <map>

void Vehicle::printInfo(ostream &output) {
    static const std::map<std::string, std::string> sizeMap = {{"S", "with 2 wheels."},
                                                               {"M", "medium car."},
                                                               {"L", "bigger car."},
                                                               {"XL", "truck."},
                                                               {"XXL", "big truck."}};

    output << this->numberPlate << ", " << this->color << " " << sizeMap.at(this->getSize());
}
