//
// Created by user12043 on 26.11.2019.
//

#ifndef GL_ASSIGMENT_SNAKE_H
#define GL_ASSIGMENT_SNAKE_H


#include <vector>
#include <sys/types.h>
#include "Direction.h"
#include "SnakeCell.h"

#define DEFAULT_SPEED 1.5f
#define TEXTURES_FOLDER "./images/"

using std::vector;

static const string TEXTURE_PATHS[]{
        string(TEXTURES_FOLDER) + "Earth.jpg",
        string(TEXTURES_FOLDER) + "Jupiter.jpg",
        string(TEXTURES_FOLDER) + "Mars.jpg",
        string(TEXTURES_FOLDER) + "Mercury.jpg",
        string(TEXTURES_FOLDER) + "Neptune.jpg",
        string(TEXTURES_FOLDER) + "PoorPluto.jpg",
        string(TEXTURES_FOLDER) + "Sun.jpg",
        string(TEXTURES_FOLDER) + "Uranus.jpg",
        string(TEXTURES_FOLDER) + "Venus.jpg"
};

class Snake {
private:
    vector<SnakeCell *> cells;
    Direction direction;
    float speed;
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
