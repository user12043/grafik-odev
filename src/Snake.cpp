//
// Created by user12043 on 26.11.2019.
//

#include <ctime>
#include <cstdlib>
#include "Snake.h"

clock_t lastStepTime = 0;

u_int pickTexture(int index) {
    if (index == -1) {
        int length = (int) TEXTURE_PATHS->length() / 2;
        index = (int) (rand() % length);
    }
    return Texture::getInstance()->getTexture(TEXTURE_PATHS[index]);
}

Snake::Snake() {
    Snake::direction = DIRECTION_DOWN;
    Snake::speed = DEFAULT_SPEED;
}

void Snake::step() {
    const clock_t currentTime = clock();
    double passed = double(currentTime - lastStepTime) / double(CLOCKS_PER_SEC) * 100;
    if (passed < speed || cells.empty()) {
        return;
    }
    lastStepTime = currentTime;

    for (auto cell : cells) {
        cell->step();
    }
    for (u_long a = cells.size() - 1; a > 0; a--) {
        SnakeCell *cell = cells.at(a - 1);
        cells.at(a)->setDirection(cell->getDirection());
    }
}

Direction Snake::getDirection() const {
    return direction;
}

void Snake::setDirection(Direction dir) {
    if (!cells.empty()) {
        Snake::direction = dir;
        cells.at(0)->setDirection(dir);
    }
}

void Snake::draw() {
    for (auto &cell : cells) {
        cell->draw();
    }
}

void Snake::addCell() {
    if (cells.empty()) {
        cells.emplace_back(new SnakeCell(0, DIRECTION_DOWN, pickTexture(6), 0.0f, 0.0f));
        return;
    }
    vec2 prevPosition = cells.back()->getPosition();
    vec2 newPosition;
    switch (cells.back()->getDirection()) {
        case DIRECTION_UP:
            newPosition.x = prevPosition.x;
            newPosition.y = prevPosition.y - STEP_SIZE;
            break;
        case DIRECTION_DOWN:
            newPosition.x = prevPosition.x;
            newPosition.y = prevPosition.y + STEP_SIZE;
            break;
        case DIRECTION_LEFT:
            newPosition.x = prevPosition.x + STEP_SIZE;
            newPosition.y = prevPosition.y;
            break;
        case DIRECTION_RIGHT:
            newPosition.x = prevPosition.x - STEP_SIZE;
            newPosition.y = prevPosition.y;
            break;
    }
    cells.emplace_back(
            new SnakeCell(cells.size(), cells.back()->getDirection(), pickTexture(-1), newPosition.x, newPosition.y));
}
