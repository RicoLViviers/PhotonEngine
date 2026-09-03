#pragma once

#include "glad/glad.h"


class Texture
{
public:
    Texture(const char* imagePath);
    void bind();

private:
    int width, height, nrChannels;
    unsigned char *data;
    GLenum format;
};