#pragma once
#include "Vector4.h";
#include "Vector3.h";

enum FaceSide {
	Front,
	Back,
	Left,
	Right,
	Top,
	Bothom
};

class Face
{
public :
	Face();
	Face(Vector3 cubePivot, FaceSide faceSide, float size);
	void generateVertex(Vector3 cubePivot);
	void generateColor();
	FaceSide m_faceSide;
	Vector3 m_color;
	Vector3 m_vertex[4]{};
	float m_size;
};

