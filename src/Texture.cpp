//
// Created by user12043 on 30.11.2019.
//

/**
 * Muaz KARATAŞ - b161210039
 * Erkam BAYINDIR - b081210006
 */

#include "Texture.h"
// enable stb image
#define STB_IMAGE_IMPLEMENTATION

#include <stb/stb_image.h>

static Texture *instance(nullptr);

Texture *Texture::getInstance() {
    if (instance == nullptr) {
        instance = new Texture();
    }
    return instance;
}

u_int Texture::getTexture(const string &fileName) {
    if (textures.count(fileName) != 0) {
        return textures.at(fileName);
    } else {
        int width, height, nrChannels;
        u_char *data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 0);
        u_int textureId;
        // initialize texture
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        // some filters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        textures[fileName] = textureId;

        //clean
        stbi_image_free(data);

        return textureId;
    }
}

void Texture::enableTexture(const string &fileName) {
    if (textures.count(fileName) != 0) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures.at(fileName));
    }
}

void Texture::enableTexture(u_int textureId) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);
}
