#include "Rubik.h"
#include "Transformaciones.h"

Rubik::Rubik() {
    generateMatrizRubik(0,0,0);
}

void Rubik::generateMatrizRubik(int x, int y, int z) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                m_rubikMatriz[i][j][k] = Vector3(x + i - 1, y + j - 1, z +
                    k - 1);
            }
        }
    }
}

void Rubik::rotate_axis_x_R() {
    Vector3 faceToRotate[3][3]{};
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            faceToRotate[i][y] = m_rubikMatriz[0][i][y];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            m_rubikMatriz[0][i][y] = Transformaciones::RotateZ(90, m_rubikMatriz[0][i][y]);
        }
    }


}
void Rubik::rotate_axis_x_M() {

}
void Rubik::rotate_axis_x_L() {

}
void Rubik::rotate_axis_y_T() {

}
void Rubik::rotate_axis_y_M() {

}
void Rubik::rotate_axis_y_B() {

}
void Rubik::rotate_axis_z_F() {

}
void Rubik::rotate_axis_z_M() {

}
void Rubik::rotate_axis_z_B() {

}