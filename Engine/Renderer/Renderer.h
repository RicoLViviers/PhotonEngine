#pragma once

class Renderer
{
public:
    Renderer();
    ~Renderer();
    void render();

private:
    unsigned int shaderProgram;
    unsigned int VBO, VAO, EBO;
};