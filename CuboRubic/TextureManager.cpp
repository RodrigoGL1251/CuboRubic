#include "TextureManager.h"


TextureManager::TextureManager() {
}

TextureManager* TextureManager::m_instance = nullptr;

TextureManager* TextureManager::getInstance()
{
    if (!m_instance) {
        m_instance = new TextureManager();
        m_instance->loadTextures();
    }

    return m_instance;
}

void TextureManager::loadTextures()
{
    glGenTextures(6, m_textures);

    for (int i = 0; i < 6; i++)
    {
        m_textures[i] = LoadBMP("Textures/texture " + i + (char)".bmp", m_textures[i]);
    }


}

GLuint TextureManager::LoadBMP(string filepath, GLuint textureID) {
    ifstream file(filepath, ios::binary);
    if (!file.is_open()) {
        file.close();
        return 0;
    }

    char header[54];
    file.read(header, 54);

    // Obtener información sobre la imagen
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Leer los datos de la imagen
    int imageSize = width * height * 3; // Suponiendo que la imagen es en formato RGB sin canal alfa
    std::vector<char> data(imageSize);
    file.read(data.data(), imageSize);

    // Cerrar el archivo
    file.close();

    // Crear la textura en OpenGL
    glBindTexture(GL_TEXTURE_2D, textureID);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data.data());
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    /*glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data.data());
    glGenerateMipmap(GL_TEXTURE_2D);*/

    return textureID;
}

GLuint TextureManager::getTextureByIndex(const int index) {
    if (index >= 6 || index < 0) {
        return m_textures[0];
    }
    return m_textures[index];
}