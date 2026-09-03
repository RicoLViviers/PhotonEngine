#pragma once

#include "glm/glm.hpp"
#include <vector>

#include "./Mesh.h"
#include "memory"

class MeshComponent
{
public:
    MeshComponent(std::shared_ptr<Mesh> mesh);

    void draw();

    std::shared_ptr<Mesh> getMesh();

private:
    std::shared_ptr<Mesh> mesh;
};