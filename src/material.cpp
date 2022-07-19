#include "material.h"
#include <iostream>
void Material::updateUniform()
{
    for (auto it = uniformIntMap.begin(); it!=uniformIntMap.end(); it++) {
        shader->setInt(it->first, it->second);
    }
    for (auto it = uniformFloatMap.begin(); it!=uniformFloatMap.end(); it++) {
        shader->setFloat(it->first, it->second);
    }
    for (auto it = uniformVec4Map.begin(); it!=uniformVec4Map.end(); it++) {
        shader->setVec4(it->first, it->second);
    }
    for (auto it = uniformTextureMap.begin(); it!=uniformTextureMap.end(); it++) {
        shader->setInt(it->first, it->second->num);
    }
}
