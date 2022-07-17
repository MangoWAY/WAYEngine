
#include "renderSystem.h"

void RenderSystem::onRender()
{
    for (int i = 0; i < rendererList.size(); i++) {
        rendererList[i]->mat->updateUniform();
        rendererList[i]->onRender();
    }
}

void RenderSystem::addRenderer(Renderer* render)
{
    rendererList.push_back(render);
}
