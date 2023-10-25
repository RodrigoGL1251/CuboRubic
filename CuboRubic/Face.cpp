#include "Face.h"



Face::Face()
{
	m_size = 0.5;
	m_faceSide = Front;
	generateVertex(Vector3());
	generateColor();
}

Face::Face(Vector3 cubePivot, FaceSide faceSide, float size)
{
	m_size = size;
	m_faceSide = faceSide;
	generateVertex(cubePivot);
	generateColor();
}

void Face::generateVertex(Vector3 cubePivot)
{
	float halfSize = m_size / 2;
	switch (m_faceSide)
	{		
	case Front:
		m_vertex[0] = Vector3(cubePivot.x - halfSize, cubePivot.y + halfSize, cubePivot.z + halfSize);
		m_vertex[1] = Vector3(cubePivot.x - halfSize, cubePivot.y - halfSize, cubePivot.z + halfSize);
		m_vertex[2] = Vector3(cubePivot.x + halfSize, cubePivot.y - halfSize, cubePivot.z + halfSize);
		m_vertex[3] = Vector3(cubePivot.x + halfSize, cubePivot.y + halfSize, cubePivot.z + halfSize);
		break;
	case Back:
		m_vertex[0] = Vector3(cubePivot.x - halfSize, cubePivot.y + halfSize, cubePivot.z - halfSize);
		m_vertex[1] = Vector3(cubePivot.x + halfSize, cubePivot.y + halfSize, cubePivot.z - halfSize);
		m_vertex[2] = Vector3(cubePivot.x + halfSize, cubePivot.y - halfSize, cubePivot.z - halfSize);
		m_vertex[3] = Vector3(cubePivot.x - halfSize, cubePivot.y - halfSize, cubePivot.z - halfSize);
		break;
	case Left:
		m_vertex[0] = Vector3(cubePivot.x - halfSize, cubePivot.y + halfSize, cubePivot.z + halfSize);
		m_vertex[1] = Vector3(cubePivot.x - halfSize, cubePivot.y + halfSize, cubePivot.z - halfSize);
		m_vertex[2] = Vector3(cubePivot.x - halfSize, cubePivot.y - halfSize, cubePivot.z - halfSize);
		m_vertex[3] = Vector3(cubePivot.x - halfSize, cubePivot.y - halfSize, cubePivot.z + halfSize);
		break;
	case Right:
		m_vertex[0] = Vector3(cubePivot.x + halfSize, cubePivot.y + halfSize, cubePivot.z + halfSize);
		m_vertex[1] = Vector3(cubePivot.x + halfSize, cubePivot.y - halfSize, cubePivot.z + halfSize);
		m_vertex[2] = Vector3(cubePivot.x + halfSize, cubePivot.y - halfSize, cubePivot.z - halfSize);
		m_vertex[3] = Vector3(cubePivot.x + halfSize, cubePivot.y + halfSize, cubePivot.z - halfSize);
		break;
	case Top:
		m_vertex[0] = Vector3(cubePivot.x - halfSize, cubePivot.y + halfSize, cubePivot.z + halfSize);
		m_vertex[1] = Vector3(cubePivot.x + halfSize, cubePivot.y + halfSize, cubePivot.z + halfSize);
		m_vertex[2] = Vector3(cubePivot.x + halfSize, cubePivot.y + halfSize, cubePivot.z - halfSize);
		m_vertex[3] = Vector3(cubePivot.x - halfSize, cubePivot.y + halfSize, cubePivot.z - halfSize);
		break;
	case Bothom:
		m_vertex[0] = Vector3(cubePivot.x - halfSize, cubePivot.y - halfSize, cubePivot.z + halfSize);
		m_vertex[1] = Vector3(cubePivot.x + halfSize, cubePivot.y - halfSize, cubePivot.z + halfSize);
		m_vertex[2] = Vector3(cubePivot.x + halfSize, cubePivot.y - halfSize, cubePivot.z - halfSize);
		m_vertex[3] = Vector3(cubePivot.x - halfSize, cubePivot.y - halfSize, cubePivot.z - halfSize);
		break;
	default:
		
		break;
	}
}

void Face::generateColor()
{
	switch (m_faceSide)
	{
	case Front:
		m_color = Vector3(0, 0, 1);
		break;
	case Back:
		m_color = Vector3(0, 1, 0);
		break;
	case Left:
		m_color = Vector3(1, 0, 0);
		break;
	case Right:
		m_color = Vector3(1, 0.5, 1);
		break;
	case Top:
		m_color = Vector3(1, 1, 1);
		break;
	case Bothom:
		m_color = Vector3(1, 1, 0);
		break;
	default:
		break;
	}
}
