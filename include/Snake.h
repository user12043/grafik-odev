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
    u_int length;
    Direction direction;
public:
    Snake();

    [[nodiscard]]
    Direction getDirection() const;

    void setDirection(Direction dir);
};


#endif //GL_ASSIGMENT_SNAKE_H
