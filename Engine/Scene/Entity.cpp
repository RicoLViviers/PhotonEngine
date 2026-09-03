#include "Entity.h"

#include "./Transform/Transform.h"
#include "./MeshComponent/MeshComponent.h"


Entity::Entity(std::shared_ptr<Mesh> mesh)
    : meshComponent(mesh)
{
}

Transform& Entity::getTransform()
{
    return transform;
}

MeshComponent& Entity::getMesh()
{
    return meshComponent;
}

