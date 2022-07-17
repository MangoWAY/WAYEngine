#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "mesh.h"
#include "material.h"
#include "renderObject.h"
#include "shader.h"

class Renderer {
public:
    Mesh* mesh = nullptr;
    Material* mat = nullptr;
    RenderObject renderObj;
    void onRender();
};

#endif
