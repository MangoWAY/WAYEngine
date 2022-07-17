#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include "shader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <renderSystem.h>

class Engine {
public:
    RenderSystem *renderSystem = nullptr;
    void onInit();
    void onUpdate();
    void onRender();
    
};



#endif

