#pragma once
//#include <GL/glew.h>
#include <GL/glut.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class TextureManager
{
private:
	static TextureManager* m_instance;
	GLuint m_textures[6];
	TextureManager();
	GLuint LoadBMP(string filepath, GLuint textureID);
	

public:
	static TextureManager* getInstance();
	void loadTextures();
	GLuint getTextureByIndex(const int index);
};

