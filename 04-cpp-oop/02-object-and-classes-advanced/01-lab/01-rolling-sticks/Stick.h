#ifndef STICK_H
#define STICK_H

class Stick {
    mutable char curStick;
    mutable int position;

public:
    Stick() : curStick('/'), position(0) {}

    int getPosition() const { return this->position; }

    char nextAnimation() const {
        switch (curStick) {
            case '/': curStick = '_'; break;
            case '_': curStick = '\\'; break;
            case '\\': curStick = '|'; break;
            case '|': curStick = '/'; position++;break;

        }

        return curStick;
    }
};

#endif // !STICK_H
