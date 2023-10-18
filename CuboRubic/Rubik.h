#pragma once
#include"Vector3.h"
enum Face
{
	Front,
	Midel,
	Back
};

class Rubik
{
public:
	Vector3 m_rubikMatriz[3][3][3]{ };
	Rubik();
	bool rotateAxisX(float angle, Face face);
	bool rotateAxisY(float angle, Face face);
	bool rotateAxisZ(float angle, Face face);

private:
	void generateMatrizRubik(int x, int y, int z);
};

