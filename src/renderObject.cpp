#include <glad/glad.h>
#include "renderObject.h"

void RenderObject::buildVAO(Mesh* mesh, Material *mat)
{
    unsigned int VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh->sizeOfVertex * sizeof(float), mesh->vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->sizeOfIndex * sizeof(int), mesh->indices, GL_STATIC_DRAW);
    
    int stride = 0;
    for (int i = 0; i<mesh->vertexSemantics.size(); i++) {
        stride += static_cast<int>(mesh->vertexSemantics[i]);
    }
    int offset = 0;
    for (int i = 0; i<mesh->vertexSemantics.size(); i++) {
        int ncomp = mesh->vertexSemantics[i];
        glVertexAttribPointer(i, ncomp, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
        glEnableVertexAttribArray(i);
        offset += ncomp;
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    isBuilt = true;
}

void RenderObject::onRender(unsigned int shaderProgram)
{
    if (!isBuilt) {
        return;
    }
    glBindVertexArray(VAO);
    glUseProgram(shaderProgram);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
