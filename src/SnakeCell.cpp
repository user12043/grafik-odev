//
// Created by user12043 on 26.11.2019.
//

#include "drawing.h"
#include "SnakeCell.h"

SnakeCell::SnakeCell(u_int order, Direction direction, u_int textureId, float positionX, float positionY) :
        order(order), direction(direction), textureId(textureId), positionX(positionX), positionY(positionY) {
    SnakeCell::rotateAngle = 0.0f;
}

void SnakeCell::draw() {
    setRotation(rotateAngle++);
    drawCircle(positionX, positionY, (order == 0) ? (CELL_RADIUS + 0.03f) : (CELL_RADIUS));
}

void SnakeCell::step() {
    switch (direction) {
        case DIRECTION_UP:
            setPosition(positionX, positionY + STEP_SIZE);
            break;
        case DIRECTION_DOWN:
            setPosition(positionX, positionY - STEP_SIZE);
            break;
        case DIRECTION_LEFT:
            setPosition(positionX - STEP_SIZE, positionY);
            break;
        case DIRECTION_RIGHT:
            setPosition(positionX + STEP_SIZE, positionY);
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
