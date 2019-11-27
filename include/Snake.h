//
// Created by user12043 on 26.11.2019.
//

#ifndef GL_ASSIGMENT_SNAKE_H
#define GL_ASSIGMENT_SNAKE_H


#include <vector>
#include <sys/types.h>
#include "Direction.h"
#include "SnakeCell.h"

using std::vector;

class Snake {
private:
    vector<SnakeCell *> cells;
    Direction direction;
public:
    Snake();

    void step();

    [[nodiscard]]
    Direction getDirection() const;

    void setDirection(Direction dir);

    void draw();

    void addCell();
};


#endif //GL_ASSIGMENT_SNAKE_H
