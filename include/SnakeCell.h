//
// Created by user12043 on 26.11.2019.
//

#ifndef GL_ASSIGMENT_SNAKECELL_H
#define GL_ASSIGMENT_SNAKECELL_H


#include <sys/types.h>
#include <glm/vec2.hpp>
#include "Direction.h"

#define CELL_RADIUS 0.1f
#define STEP_SIZE 0.2f

using glm::vec2;

class SnakeCell {
private:
    u_int order;
    Direction direction;
    u_int textureId;
    float positionX;
    float positionY;
    float rotateAngle;
public:
    SnakeCell(u_int order, Direction direction, u_int textureId, float positionX, float positionY);

    virtual ~SnakeCell() = default;

    void draw();

    void step();

    vec2 getPosition();

    void setPosition(float positionX, float positionY);

    [[nodiscard]] Direction getDirection() const;

    void setDirection(Direction direction);
};


#endif //GL_ASSIGMENT_SNAKECELL_H
