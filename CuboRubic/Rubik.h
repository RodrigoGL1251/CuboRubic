#pragma once
#include"Vector3.h"
class Rubik
{
public:
	Vector3 m_rubikMatriz[3][3][3]{ };
	Rubik();
	void rotate_axis_x_R();
	void rotate_axis_x_M();
	void rotate_axis_x_L();
	void rotate_axis_y_T();
	void rotate_axis_y_M();
	void rotate_axis_y_B();
	void rotate_axis_z_F();
	void rotate_axis_z_M();
	void rotate_axis_z_B();

private:
	void generateMatrizRubik(int x, int y, int z);

};

