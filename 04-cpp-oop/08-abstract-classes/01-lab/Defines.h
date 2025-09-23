#pragma once

#include "Position.h"
#include "Defines.h"

int Position::MinPosition = 0;
int Position::MaxPosition = WORLD_SIZE - 1;


const int WORLD_SIZE = 30;

#include "Engine.h"

void Engine::act() {
    for (auto o: creatures)
        o->act();
}

void Engine::render(Renderer &r) {
    for (auto o: creatures)
        r.render(o->getPosition(), o->getImage());
}
