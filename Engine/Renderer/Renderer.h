#pragma once
#include "../Scene/Entity.h"

#include <memory>
class Renderer
{
public:
    Renderer();
    ~Renderer();
    void render();

private:
    unsigned int shaderProgram;
    unsigned int VBO, VAO, EBO;
    std::unique_ptr<Entity> cube;

};