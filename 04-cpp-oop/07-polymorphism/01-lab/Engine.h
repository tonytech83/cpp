//
// Created by tonytech on 15.09.2025.
//

#ifndef CPP_ENGINE_H
#define CPP_ENGINE_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>

#include "Particle.h"
#include "Screen.h"

#include "Lightning.h"
#include "Meteorite.h"
#include "Raindrop.h"
#include "Snowflake.h"

void updateParticles(std::list<Particle *> &particles) {
    std::list<Particle *> newParticles;
    auto i = particles.begin();
    while (i != particles.end()) {
        Particle *p = *i;

        if (!p->exists()) {
            i = particles.erase(i);
            delete p;
            continue;
        } else {
            p->update(newParticles);

            i++;
        }
    }

    std::copy(newParticles.begin(), newParticles.end(), std::back_inserter(particles));
}

template<typename Pixel>
void renderParticles(Screen<Pixel> &screen, const std::list<Particle *> particles) {
    screen.clear();
    for (auto p: particles) {
        Position pos = p->getPosition();
        screen.set(pos.row, pos.col, p->getPixel());
    }
    screen.render();
}

Position randomTopPosition(int width) { return Position(0, rand() % width); }

void generateRandomParticles(std::list<Particle *> &particles, int width) {
    static int executions = 0;
    executions++;
    srand(executions * time(nullptr));

    const int newParticlesChancePct = 30;
    if (rand() % 100 < newParticlesChancePct) {
        int numNew = 1 + rand() % 3;

        const int numTypes = 4;
        Particle *newParticle = nullptr;
        Position pos = randomTopPosition(width);
        for (int i = 0; i < numNew; i++) {
            int type = rand() % numTypes;
            switch (type) {
                case 0:
                    newParticle = new Raindrop(pos, 30);
                    break;
                case 1:
                    newParticle = new Snowflake(pos, 10 + rand() % 20);
                    break;
                case 2:
                    newParticle = new Meteorite(pos, 30, 2 + rand() % 3);
                    break;
                case 3:
                    newParticle = new Lightning(pos, 20 + rand() % 30);
                    break;
                default:
                    break;
            }
        }

        if (newParticle != nullptr) {
            particles.push_back(newParticle);
        }
    }
}

#endif // CPP_ENGINE_H
