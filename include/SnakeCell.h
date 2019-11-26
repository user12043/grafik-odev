//
// Created by user12043 on 26.11.2019.
//

#ifndef GL_ASSIGMENT_SNAKECELL_H
#define GL_ASSIGMENT_SNAKECELL_H


#include <sys/types.h>
#include "Direction.h"

class SnakeCell {
private:
    u_int order;
    Direction direction;
    u_int textureId;
public:
    SnakeCell(u_int order, Direction direction, u_int textureId);

    virtual ~SnakeCell() = default;
};


#endif //GL_ASSIGMENT_SNAKECELL_H
