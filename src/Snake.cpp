//
// Created by user12043 on 26.11.2019.
//

#include "Snake.h"

Snake::Snake() {
    this->direction = DIRECTION_DOWN;
    cells.emplace_back(new SnakeCell(0, DIRECTION_DOWN, 0));
    length = 1;
}

Direction Snake::getDirection() const {
    return direction;
}

void Snake::setDirection(Direction dir) {
    Snake::direction = dir;
}
