#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Eigen/Dense"
#include <string>

class Texture {
public:
    static int CurID;
    Texture();
    ~Texture();
    std::string path;
    bool dirty = true;
    unsigned int ID;
    int num;
    void uploadTexture(const std::string path);
    void setDirty(bool flag);
};

#endif
