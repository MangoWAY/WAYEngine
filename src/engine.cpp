#include "engine.h"
#include "Eigen/Dense"

void Engine::onInit()
{
    if (renderSystem == nullptr) {
        renderSystem = new RenderSystem();
    }
    Renderer *ren = new Renderer();
    float* vertices = new float[] {
        0.5f, 0.5f, 0.0f,   // 右上角
        0.5f, -0.5f, 0.0f,  // 右下角
        0.1f, -0.5f, 0.0f, // 左下角
        0.1f, 0.5f, 0.0f   // 左上角
    };

    unsigned int* indices = new unsigned int[] {
        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
    };
    ren->mesh = new Mesh();
    ren->mesh->vertices = vertices;
    ren->mesh->indices = indices;
    ren->mesh->vertexSemantics = std::vector<VertexSemantics>{VertexSemantics::Position};
    ren->mesh->sizeOfIndex = 6;
    ren->mesh->sizeOfVertex = 4 * 3;
    ren->mat = new Material();
    ren->mat->shader = new Shader("./src/vert.vert","./src/frag.frag");
    ren->mat->uniformVec4Map["color"] = Eigen::Vector4f(0.0,1.0,0.0,1.0);
    renderSystem->addRenderer(ren);
}

void Engine::onRender()
{
    renderSystem->onRender();
}

void Engine::onUpdate()
{
    
}
