//
// Created by tonytech on 15.09.2025.
//

#ifndef CPP_RAINDROP_H
#define CPP_RAINDROP_H

#include "Particle.h"

class Raindrop : public Particle {

public:
    Raindrop(Position position, int updatesRemaining) : Particle(position, '|', updatesRemaining) {}

    virtual void update(std::list<Particle *> &producedParticlesOutput) override {
        Particle::update(producedParticlesOutput);

        position = position.nextRow();
    }
};

#endif // CPP_RAINDROP_H
