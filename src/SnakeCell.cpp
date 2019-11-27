//
// Created by user12043 on 26.11.2019.
//

#include "drawing.h"
#include "SnakeCell.h"

SnakeCell::SnakeCell(u_int order, Direction direction, u_int textureId, float positionX, float positionY) :
        order(order), direction(direction), textureId(textureId), positionX(positionX), positionY(positionY) {
    SnakeCell::stepSize = CELL_RADIUS * DEFAULT_SPEED;
    SnakeCell::speed = DEFAULT_SPEED;
}

void SnakeCell::draw() {
    drawCircle(positionX, positionY, CELL_RADIUS);
}

void SnakeCell::step() {
    switch (direction) {
        case DIRECTION_UP:
            setPosition(positionX, positionY - stepSize);
            break;
        case DIRECTION_DOWN:
            setPosition(positionX, positionY + stepSize);
            break;
        case DIRECTION_LEFT:
            setPosition(positionX - stepSize, positionY);
            break;
        case DIRECTION_RIGHT:
            setPosition(positionX + stepSize, positionY);
            break;
    }
}

vec2 SnakeCell::getPosition() {
    return vec2(positionX, positionY);
}

void SnakeCell::setPosition(float positionX, float positionY) {
    SnakeCell::positionX = positionX;
    SnakeCell::positionY = positionY;
}

Direction SnakeCell::getDirection() const {
    return direction;
}

void SnakeCell::setDirection(Direction direction) {
    SnakeCell::direction = direction;
}
