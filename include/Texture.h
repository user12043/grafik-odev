//
// Created by user12043 on 30.11.2019.
//

#ifndef GL_ASSIGMENT_TEXTURE_H
#define GL_ASSIGMENT_TEXTURE_H

#include <glad/glad.h>
#include <map>
#include <sys/types.h>

using std::map;
using std::string;

class Texture {
private:
    map<string, u_int> textures;

    Texture() = default;

public:
    static Texture *getInstance();

    u_int getTexture(const string &fileName);

    void enableTexture(const string &fileName);

    static void enableTexture(u_int textureId);
};

#endif //GL_ASSIGMENT_TEXTURE_H
