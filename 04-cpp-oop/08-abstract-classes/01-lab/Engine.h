//
// Created by tonytech on 23.09.2025.
//

#ifndef CPP_ENGINE_H
#define CPP_ENGINE_H

#include <memory>
#include <vector>

#include "Organism.h"
#include "RenderingUtils.h"

class Engine : public Actionable {

public:
    void add(std::shared_ptr<Organism> o) { creatures.push_back(o); }

    virtual void act() override;

    void render(Renderer &r);

protected:
    std::vector<std::shared_ptr<Organism>> creatures;
};

#endif // CPP_ENGINE_H
