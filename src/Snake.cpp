//
// Created by user12043 on 26.11.2019.
//

#include "Snake.h"

Snake::Snake() {
    Snake::direction = DIRECTION_DOWN;
    cells.emplace_back(new SnakeCell(0, DIRECTION_DOWN, 0, 0.0f, 0.0f));
}

void Snake::step() {
    for (u_long a = cells.size(); a > 0; a--) {
        SnakeCell *cell = cells.at(a - 1);
        if (a != cells.size()) {
            cell->setDirection(cells.at(a)->getDirection());
        }
        cell->step();
    }
}

Direction Snake::getDirection() const {
    return direction;
}

void Snake::setDirection(Direction dir) {
    Snake::direction = dir;
}

void Snake::draw() {
    for (auto &cell : cells) {
        cell->draw();
    }
}

void Snake::addCell() {
    vec2 prevPosition = cells.back()->getPosition();
    vec2 newPosition;
    step();
    switch (cells.back()->getDirection()) {
        case DIRECTION_UP:
            newPosition.x = prevPosition.x;
            newPosition.y = prevPosition.y - (CELL_RADIUS * 2);
            break;
        case DIRECTION_DOWN:
            newPosition.x = prevPosition.x;
            newPosition.y = prevPosition.y + (CELL_RADIUS * 2);
            break;
        case DIRECTION_LEFT:
            newPosition.x = prevPosition.x - (CELL_RADIUS * 2);
            newPosition.y = prevPosition.y;
            break;
        case DIRECTION_RIGHT:
            newPosition.x = prevPosition.x + (CELL_RADIUS * 2);
            newPosition.y = prevPosition.y;
            break;
    }
    cells.emplace_back(new SnakeCell(cells.size(), cells.back()->getDirection(), 0, newPosition.x, newPosition.y));
}
