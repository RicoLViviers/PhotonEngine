#include "MeshComponent.h"

#include <memory>

#include "./Mesh.h"
#include "glad/glad.h"

MeshComponent::MeshComponent(std::shared_ptr<Mesh> mesh) : mesh(mesh)
{
}

void MeshComponent::draw()
{
    glBindVertexArray(mesh->getVAO());

    glDrawElements(
        GL_TRIANGLES,
        mesh->getIndexCount(),
        GL_UNSIGNED_INT,
        nullptr
    );
}