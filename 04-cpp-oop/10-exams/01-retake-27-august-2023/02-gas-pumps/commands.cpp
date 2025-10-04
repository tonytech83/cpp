//
// Created by tonytech on 04.10.2025.
//
#include "commands.h"
#include <iostream>
#include "defines.h"

// End Command

auto EndCommand::process() -> void {
    const auto &reservoir = GasReservoir::get();
    outputTicks(std::cout) << ": Final gas quantity: " << reservoir.getQuantity() << " kg3" << std::endl;
}

// Init Command

InitCommand::InitCommand(std::istream &istr) : Command(istr), initQ(0) { istr >> initQ; };

auto InitCommand::process() -> void {
    auto &reservoir = GasReservoir::get();
    reservoir.setQuantity(initQ);
    outputTicks(std::cout) << ": Gas quantity: " << reservoir.getQuantity() << " kg3" << std::endl;
};

InitCommand::~InitCommand() = default;

// In Command

InCommand::InCommand(std::istream &istr) : TwoParametersCommand(istr) {};

auto InCommand::process() -> void {
    auto &reservoir = GasReservoir::get();

    const int quantity = this->getPar1();
    const int time = this->getPar2();
    const int addedQuantity = quantity * time;

    reservoir.setQuantity(reservoir.getQuantity() + addedQuantity);
    reservoir.addCycles(time);

    // Pumping in 5 kg3 for 30 hours, remaining 20150 kg3
    outputTicks(std::cout) << ": Pumping in " << quantity << " kg3 for " << time << " hours, remaining "
                           << reservoir.getQuantity() << " kg3" << std::endl;
};

InCommand::~InCommand() = default;

// Out Command

OutCommand::OutCommand(std::istream &istr) : TwoParametersCommand(istr) {};

auto OutCommand::process() -> void {
    auto &reservoir = GasReservoir::get();
    const int quantity = this->getPar1();
    const int time = this->getPar2();

    reservoir.addCycles(time);

    if (reservoir.getQuantity() <= 0) {
        outputTicks(std::cout) << ": Gas Storage Empty." << std::endl;
    } else {
        int removedQuantity = quantity * time;
        int shortage = 0;

        if (removedQuantity > reservoir.getQuantity()) {
            shortage = reservoir.getQuantity() - removedQuantity;
            removedQuantity = reservoir.getQuantity();
            reservoir.setQuantity(0);
        } else {
            reservoir.setQuantity(reservoir.getQuantity() - removedQuantity);
        }

        if (shortage) {
            // Hour 0033: Delivering out 19750 kg3 (shortage 250 kg3), remaining 0 kg3
            outputTicks(std::cout) << ": Delivering out " << removedQuantity << " kg3 (shortage " << abs(shortage)
                                   << " kg3), remaining " << reservoir.getQuantity() << " kg3" << std::endl;
        } else {
            // Hour 0032: Delivering out 400 kg3, remaining 19750 kg3
            outputTicks(std::cout) << ": Delivering out " << removedQuantity << " kg3, remaining "
                                   << reservoir.getQuantity() << " kg3" << std::endl;
        }
    }
}

OutCommand::~OutCommand() = default;

// Demand Command

DemandCommand::DemandCommand(std::istream &istr) : TwoParametersCommand(istr) {};

auto DemandCommand::process() -> void {
    const auto &reservoir = GasReservoir::get();
    const int quantity = this->getPar1();
    const int time = this->getPar2();

    const int requestedQuantity = quantity * time;

    if (reservoir.getQuantity() <= 0)
        outputTicks(std::cout) << ": CHECK: Gas Storage Empty." << std::endl;
    else if (requestedQuantity > reservoir.getQuantity()) {
        // : CHECK: Shortage of 16800: availability 40 for 30 hours
        const int shortage = requestedQuantity - reservoir.getQuantity();
        outputTicks(std::cout) << ": CHECK: Shortage of " << shortage << ": availability "
                               << reservoir.getQuantity() / time << " for " << time << " hours" << std::endl;
    } else {
        outputTicks(std::cout) << ": CHECK: OK." << std::endl;
    }
};

DemandCommand::~DemandCommand() = default;
