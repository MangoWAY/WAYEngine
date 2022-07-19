#ifndef MATERIAL_H
#define MATERIAL_H

#include <glad/glad.h>
#include "shader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include "texture.h"
#include "Eigen/Dense"

class Material {
public:
    std::string name;
    std::map<std::string, int> uniformIntMap;
    std::map<std::string, float> uniformFloatMap;
    std::map<std::string, Eigen::Vector4f> uniformVec4Map;
    std::map<std::string, Texture*> uniformTextureMap;
    void updateUniform();
    Shader *shader = nullptr;
    
};



#endif
