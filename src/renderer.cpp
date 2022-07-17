#include "renderer.h"

void Renderer::onRender()
{
    if (!renderObj.isBuilt){
        renderObj.buildVAO(mesh, mat);
    }
    renderObj.onRender(mat->shader->ID);
}
