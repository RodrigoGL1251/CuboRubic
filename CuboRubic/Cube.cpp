#include "Cube.h"

Cube::Cube()
{
	m_size = 1;
	m_pivot = Vector3();
	m_rotation = Vector4();
	generateFaces();
}

Cube::Cube(Vector3 pivot, float size, Vector4 rotation)
{
	m_size = size;
	m_pivot = pivot;
	m_rotation = rotation;
	generateFaces();
}

void Cube::generateFaces()
{
	for (int i = 0; i < 6; i++) {
		m_faces[i] = Face(m_pivot, (FaceSide)i, m_size);
	}
}
