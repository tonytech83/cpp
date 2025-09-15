//
// Created by tonytech on 15.09.2025.
//

#ifndef CPP_METEORITE_H
#define CPP_METEORITE_H

#include "Particle.h"

class Meteorite : public Particle {

    int tailLenght;
    bool leftDirection;

    class Tail : public Particle {

    public:
        Tail(Position pos, char directionChar, int lifespan) : Particle(pos, directionChar, lifespan) {}
    };

public:
    Meteorite(Position pos, int lifespan, int tailLenght) :
        Particle(pos, 'o', lifespan), tailLenght(tailLenght), leftDirection(rand() % 2) {}

    virtual void update(std::list<Particle *> &producedParticlesOutput) override {
        Particle::update(producedParticlesOutput);

        Particle *tail = new Tail(position, leftDirection ? '/' : '\\', tailLenght);
        producedParticlesOutput.push_back(tail);

        if (leftDirection)
            position = position.nextRow().prevCol();
        else
            position = position.nextRow().nextCol();
    }
};

#endif // CPP_METEORITE_H
