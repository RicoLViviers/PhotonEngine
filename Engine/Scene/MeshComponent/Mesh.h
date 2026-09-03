#pragma once

#include "glm/glm.hpp"
#include <vector>
class Mesh
{
public:
    Mesh(
        const std::vector<float>& vertices,
        const std::vector<unsigned int>& indices
    );

    ~Mesh();
    
    void bind();

    unsigned int getVAO() const;
    unsigned int getIndexCount() const;
    
private:
    unsigned int VBO, VAO, EBO;
    
    unsigned int indexCount;
    
};