//
// Created by tonytech on 15.09.2025.
//

#ifndef CPP_LIGHTNING_H
#define CPP_LIGHTNING_H

#include "Particle.h"

class Lightning : public Particle {

    int length;

    class Spark : public Particle {
    public:
        Spark(Position pos, bool directon) : Particle(pos, directon ? '<' : '>', 0) {}
    };

public:
    Lightning(Position pos, int length) : Particle(pos, ' ', 1), length(length) {}

    virtual void update(std::list<Particle *> &producedParticlesOutput) override {
        Particle::update(producedParticlesOutput);

        Position nextPos = position;
        for (int i = 0; i < length; i++) {
            bool isLeft = rand() % 2;

            producedParticlesOutput.push_back(new Spark(nextPos, isLeft));

            if (isLeft)
                nextPos = nextPos.nextRow().prevCol();
            else
                nextPos = nextPos.nextRow().nextCol();
        }
    }
};

#endif // CPP_LIGHTNING_H
