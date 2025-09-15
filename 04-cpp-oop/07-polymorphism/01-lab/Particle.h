//
// Created by tonytech on 15.09.2025.
//

#ifndef CPP_PARTICLE_H
#define CPP_PARTICLE_H

#include <list>

#include "Position.h"

class Particle {
protected:
    Position position;
    char symbol;
    int updatesRemaining;

public:
    Particle(Position position, char symbol, int updatesRemaining) :
        position(position), symbol(symbol), updatesRemaining(updatesRemaining) {}

    virtual void update(std::list<Particle *> &producedParticlesOutput) { this->updatesRemaining--; }

    bool exists() const { return this->updatesRemaining > 0; }

    Position getPosition() const { return this->position; }

    char getPixel() const { return this->symbol; }
};

#endif // CPP_PARTICLE_H
