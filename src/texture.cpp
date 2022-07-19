#include "texture.h"
#include "stb_image.h"
int Texture::CurID = 0;

Texture::Texture()
{
    glActiveTexture(GL_TEXTURE0 + Texture::CurID);
    num = Texture::CurID;
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    Texture::CurID++;
}

Texture::~Texture(){
    Texture::CurID--;
}

void Texture::setDirty(bool flag)
{
    dirty = flag;
}


void Texture::uploadTexture(const std::string path)
{
    if (!dirty) {
        return;
    }
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    dirty = false;
    stbi_image_free(data);
}
