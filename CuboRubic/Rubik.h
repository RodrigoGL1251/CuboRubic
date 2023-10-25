#pragma once
#include "Cube.h"

class Rubik
{
public:
	Vector3 m_pivot;
	float m_size = 0.8;
	float m_rotationSpeed = 5;
	Cube m_cubeMatriz[3][3][3]{ };

	Rubik();

	Rubik(Vector3 pivot, float size);
	void generateCubeMatrix();
};

