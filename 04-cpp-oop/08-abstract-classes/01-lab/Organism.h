#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>
#include "Actionalbe.h"
#include "Position.h"

class Organism : public Actionable {
private:
    std::string name;
    Position position;

protected:
    virtual void move() = 0;

public:
    Organism() : position(0, 0) {}

    Organism(const std::string &name, const Position &pos) : name(name), position(pos) {}

    void setPosition(const Position &pos) { position = pos; }
    const Position &getPosition() const { return position; }

    const std::string &getName() const { return name; }

    virtual std::string getImage() const = 0;
};

#endif // !ORGANISM_H
