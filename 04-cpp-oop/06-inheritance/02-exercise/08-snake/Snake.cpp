//
// Created by tonytech on 14.9.2025.
//
#include "Snake.h"
using namespace std;

Snake::Snake(const int fieldRows, const int fieldCols, const Point &startPos) :
    _FIELD_ROWS(fieldRows), _FIELD_COLS(fieldCols), _currPos(startPos) {
    _snakeNodes.push_back(_currPos);
}

Snake::~Snake() = default;

auto updateSnakeHead(const Direction dir, Point &headPos) -> void {
    switch (dir) {
        case Direction::UP:
            headPos.row--;
            break;
        case Direction::DOWN:
            headPos.row++;
            break;
        case Direction::LEFT:
            headPos.col--;
            break;
        case Direction::RIGHT:
            headPos.col++;
            break;
    }
}

auto checkNewHeadPosition(const Point &newPos, const int &filedRows, const int &fieldCols,
                          const vector<Point> &obstacles, const deque<Point> &_snakeNodes) -> bool {

    // Snake is outside of field
    if (newPos.row < 0 || newPos.row >= filedRows || newPos.col < 0 || newPos.col >= fieldCols)
        return false;

    // Snake byte obstacle
    for (auto o: obstacles)
        if (o == newPos)
            return false;

    // Snake bite ourselves
    for (auto node: _snakeNodes)
        if (node == newPos)
            return false;

    return true;
}

auto Snake::move(const Direction dir, const vector<Point> &obstacles, vector<Point> &powerUps) -> StatusCode {

    updateSnakeHead(dir, _currPos);

    if (!checkNewHeadPosition(_currPos, _FIELD_ROWS, _FIELD_COLS, obstacles, _snakeNodes))
        return StatusCode::SNAKE_DEAD;

    // Snake byte powerUp
    for (auto it = powerUps.begin(); it != powerUps.end(); ++it) {
        if (*it == _currPos) {
            this->_snakeNodes.push_front(_currPos); // update snake body
            powerUps.erase(it); // remove the powerUp
            return StatusCode::SNAKE_GROWING;
        }
    }

    this->_snakeNodes.push_front(_currPos); // update snake body
    this->_snakeNodes.pop_back(); // remove last snake node
    return StatusCode::SNAKE_MOVING;
}

auto Snake::getSnakeNodes() -> deque<Point> & { return this->_snakeNodes; }
