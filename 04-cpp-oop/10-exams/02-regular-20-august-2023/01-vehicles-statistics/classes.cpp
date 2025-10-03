//
// Created by tonytech on 3.10.2025.
//
#include "classes.h"

void Vehicle::printInfo(ostream &output) {
    string carSize;
    if (this->getSize() == "S")
        carSize = "with 2 wheels.";
    else if (this->getSize() == "M")
        carSize = "medium car.";
    else if (this->getSize() == "L")
        carSize = "bigger car.";
    else if (this->getSize() == "XL")
        carSize = "truck.";
    else
        carSize = "big truck.";

    output << this->numberPlate << ", " << this->color << " " << carSize;
}
