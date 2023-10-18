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

bool Rubik::rotateAxisX(float angle, Face face) {
    Vector3 faceToRotate[3][3]{};
    bool rotationcomplete = false;
    
    switch (face)
    {
    case Front:
        //Rotando los vectores de la cara de la matriz
        for (int i = 0; i < 3; i++) {
            for (int y = 0; y < 3; y++) {
                m_rubikMatriz[0][i][y] = Transformaciones::RotateZ(90, m_rubikMatriz[0][i][y]);
            }
        }
        
        
        //if (m_rubikMatriz[0][0][0].y == 0 && m_rubikMatriz[0][0][0].z == 0) {
        //    //Copiando una parte de la matriz del cubo
        //    for (int i = 0; i < 3; i++) {
        //        for (int y = 0; y < 3; y++) {
        //            faceToRotate[i][y] = m_rubikMatriz[0][i][y];
        //        }
        //    }
        //    
        //    int x;
        //    int y = 2;
        //    for (int i = 0; i < 3; i++) {
        //        x = 0;
        //        for (int j = 0; j < 3; j++) {
        //            m_rubikMatriz[0][x][y] = faceToRotate[i][j];
        //            x++;
        //        }
        //        y--;
        //    }
        //    rotationcomplete = true;
        //}        
        break;
    case Midel:

        break;
    case Back:

        break;
    default:
        break;
    }

    return rotationcomplete;
}
bool Rubik::rotateAxisY(float angle, Face face) {
    return false;
}
bool Rubik::rotateAxisZ(float angle, Face face) {
    return false;
}