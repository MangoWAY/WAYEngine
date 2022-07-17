#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

#include "mesh.h"
#include "material.h"
#include <glad/glad.h>

class RenderObject {
public:
    void buildVAO(Mesh *mesh, Material *mat);
    void onRender(unsigned int shaderProgram);
    unsigned int VAO;
    bool isBuilt = false;
};

#endif
