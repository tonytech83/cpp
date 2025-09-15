//
// Created by tonytech on 15.09.2025.
//
#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>
#include <thread>

#include <list>

#include "ConsoleScreen.h"
#include "Engine.h"
#include "Particle.h"

int main() {
    const int width = 80;
    const int height = 20;

    std::list<Particle *> particles;
    auto screen = ConsoleScreen(height, width, ' ');

    bool running = true;
    while (running) {
        generateRandomParticles(particles, width);

        renderParticles(screen, particles);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        updateParticles(particles);
    }

    return 0;
}
