#include "engine.h"
#include "Eigen/Dense"
#include "texture.h"
void Engine::onInit()
{
    if (renderSystem == nullptr) {
        renderSystem = new RenderSystem();
    }
    Renderer *ren = new Renderer();
    float* vertices = new float[] {
        0.5f, 0.5f, 0.0f, 1.0f,1.0f,  // 右上角
        0.5f, -0.5f, 0.0f, 1.0f,0.0f, // 右下角
        -0.5f, -0.5f, 0.0f, 0.0f,0.0f,// 左下角
        -0.5f, 0.5f, 0.0f,0.0f,1.0f   // 左上角
    };

    unsigned int* indices = new unsigned int[] {
        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
    };
    ren->mesh = new Mesh();
    ren->mesh->vertices = vertices;
    ren->mesh->indices = indices;
    ren->mesh->vertexSemantics = std::vector<VertexSemantics>{VertexSemantics::Position,VertexSemantics::Texcoord0};
    ren->mesh->sizeOfIndex = 6;
    ren->mesh->sizeOfVertex = 4 * 5;
    ren->mat = new Material();
    ren->mat->shader = new Shader("/Users/bytedance/Documents/Byted-GitProjs/WAYEngine/src/vert.vert","/Users/bytedance/Documents/Byted-GitProjs/WAYEngine/src/frag.frag");
    ren->mat->uniformVec4Map["color"] = Eigen::Vector4f(0.0,1.0,0.0,1.0);
    Texture* tex = new Texture();
    tex->path = "/Users/bytedance/Documents/Byted-GitProjs/WAYEngine/src/van.jpg";
    tex->uploadTexture(tex->path);
    
    Texture* tex1 = new Texture();
    tex1->path = "/Users/bytedance/Documents/Byted-GitProjs/WAYEngine/src/long.jpg";
    tex1->uploadTexture(tex1->path);
    
    ren->mat->uniformTextureMap["van"] = tex;
    ren->mat->uniformTextureMap["l"] = tex1;
    renderSystem->addRenderer(ren);
}

void Engine::onRender()
{
    renderSystem->onRender();
}

void Engine::onUpdate()
{
    
}
