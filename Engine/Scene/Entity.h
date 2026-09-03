#pragma once
#include "./MeshComponent/MeshComponent.h"
#include "./Transform/Transform.h"
class Entity
{
public:
    Entity(std::shared_ptr<Mesh> mesh);

    Transform& getTransform();
    MeshComponent& getMesh();


private:
    Transform transform;
    MeshComponent meshComponent;
};