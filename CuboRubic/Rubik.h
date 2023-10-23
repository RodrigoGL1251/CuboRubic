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
	float m_rotationSpeed = 5;
	int m_rotateDirection = 0;

	float m_rotateAngleFrontX = 0;
	float m_rotateAngleMidleX = 0;
	float m_rotateAngleBackX = 0;
	float m_rotateAngleFrontY = 0;
	float m_rotateAngleMidleY = 0;
	float m_rotateAngleBackY = 0;
	float m_rotateAngleFrontZ = 0;
	float m_rotateAngleMidleZ = 0;
	float m_rotateAngleBackZ = 0;


	bool m_isRotatingFrontX = false;
	bool m_isRotatingMidleX = false;
	bool m_isRotatingBackX = false;
	bool m_isRotatingFrontY = false;
	bool m_isRotatingMidleY = false;
	bool m_isRotatingBackY = false;
	bool m_isRotatingFrontZ = false;
	bool m_isRotatingMidleZ = false;
	bool m_isRotatingBackZ = false;


	Vector3 m_rubikMatriz[3][3][3]{ };
	Rubik();
	bool rotateAxisX(float angle, Face face);
	bool rotateAxisY(float angle, Face face);
	bool rotateAxisZ(float angle, Face face);

private:
	void generateMatrizRubik(int x, int y, int z);
};

