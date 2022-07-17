#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

enum VertexSemantics{
    Position = 3,
    Texcoord0 = 2
};

class Mesh {

public:
    float *vertices = nullptr;
    int sizeOfVertex;
    unsigned int *indices;
    int sizeOfIndex;
    std::vector<VertexSemantics> vertexSemantics;
};

#endif
