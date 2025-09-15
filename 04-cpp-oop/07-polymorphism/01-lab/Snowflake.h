//
// Created by tonytech on 15.09.2025.
//

#ifndef CPP_SNOWFLAKE_H
#define CPP_SNOWFLAKE_H

#include "Particle.h"

class Snowflake : public Particle {

    int lastMoveDown;

public:
    Snowflake(Position position, int updatesRemaining) : Particle(position, '*', updatesRemaining), lastMoveDown(0) {}

    virtual void update(std::list<Particle *> &producedParticlesOutput) override {
        Particle::update(producedParticlesOutput);

        if (lastMoveDown >= 2) {
            position = position.nextRow();
            lastMoveDown = 0;
        }
        lastMoveDown++;

        switch (rand() % 2) {
            case 0:
                position = position.nextCol();
                break;
            case 1:
                position = position.prevCol();
                break;
        }
    }
};

#endif // CPP_SNOWFLAKE_H
