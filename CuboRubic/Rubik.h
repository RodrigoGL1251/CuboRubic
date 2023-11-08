#pragma once
#include "Cube.h"


class Rubik
{
public:
	bool m_isRotating = false;
	float m_size = 0.8;
	float m_rotationSpeed = 5;
	int m_rotationdirection = 1;
	float m_currentRotateGrades = 0;
	FaceSide m_faceToRotate = Front;
	Vector3 m_pivot;
	Cube m_cubeMatriz[3][3][3]{ };

	Rubik();
	Rubik(Vector3 pivot, float size);

	void generateCubeMatrix();
	void setAndStartRotationFace(FaceSide faceSide);
	void changeRotationDirection();
	void rotationManager();
	void rotateFrontFace();
	void rotateBackFace();
	void rotateRigthFace();
	void rotateLeftFace();
	void rotateTopFace();
	void rotateBothomFace();
};	

