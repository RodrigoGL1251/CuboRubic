#pragma once
#include "Face.h"

class Cube
{
public:
	float m_size;
	Face m_faces[6];
	Vector3 m_pivot;
	Vector4 m_rotation;
	Cube();
	Cube(Vector3 pivot, float size, Vector4 rotation);
	void generateFaces();
};

