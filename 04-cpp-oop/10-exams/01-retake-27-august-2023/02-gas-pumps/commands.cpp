//
// Created by tonytech on 04.10.2025.
//
#include "commands.h"
#include "defines.h"

// End Command

auto EndCommand::process() -> void {}

// Init Command

InitCommand::InitCommand(std::istream &istr) : Command(istr), initQ(0) { istr >> initQ; };

auto InitCommand::process() -> void { std::cout << "Hour 0000: Gas quantity: " << this->initQ << " kg3" << std::endl; };

InitCommand::~InitCommand() = default;

// In Command

InCommand::InCommand(std::istream &istr) : TwoParametersCommand(istr) {};

auto InCommand::process(void) -> void {};

InCommand::~InCommand() = default;

// Out Command

OutCommand::OutCommand(std::istream &istr) : TwoParametersCommand(istr) {};

auto OutCommand::process(void) -> void {}

OutCommand::~OutCommand() = default;

// Demand Command

DemandCommand::DemandCommand(std::istream &istr) : TwoParametersCommand(istr) {};

auto DemandCommand::process(void) -> void {};

DemandCommand::~DemandCommand() = default;
