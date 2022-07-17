
#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "renderer.h"

class RenderSystem {
public:
    void onRender();
    void addRenderer(Renderer* render);
    std::vector<Renderer*> rendererList;
};

#endif
