#include <iostream>
#include <string>
#include <vector>

#include <chrono>
#include <thread>

#include "Cat.h"
#include "Defines.h"
#include "Engine.h"
#include "Mouse.h"
#include "Organism.h"
#include "RenderingUtils.h"

void initEngine(Engine &e) {
    e.add(std::shared_ptr<Organism>(new Cat(Position(0, 0))));
    e.add(std::shared_ptr<Organism>(new Mouse(Position(1, 1))));
    e.add(std::shared_ptr<Organism>(new Cat(Position(0, 0))));
    e.add(std::shared_ptr<Organism>(new Mouse(Position(1, 1))));
    e.add(std::shared_ptr<Organism>(new Cat(Position(0, 0))));
    e.add(std::shared_ptr<Organism>(new Mouse(Position(1, 1))));
    e.add(std::shared_ptr<Organism>(new Cat(Position(0, 0))));
}

int main() {
    Renderer r(WORLD_SIZE);
    Engine e;
    initEngine(e);

    while (true) {

        e.act();

        e.render(r);
        r.flushToScreen();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
