#include "Rubik.h"
#include "Transformaciones.h"

Rubik::Rubik()
{
    m_size = 1;
    m_pivot = Vector3();
    generateCubeMatrix();
}
Rubik::Rubik(Vector3 pivot, float size) {
    m_size = size;
    m_pivot = pivot;
    generateCubeMatrix();
}



void Rubik::generateCubeMatrix() {
    float thirdOfSize = m_size / 3;
    Vector3 cubePivot;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cubePivot = Vector3(i * thirdOfSize - thirdOfSize, j * thirdOfSize - thirdOfSize, k * thirdOfSize - thirdOfSize);
                m_cubeMatriz[i][j][k] = Cube(cubePivot, thirdOfSize-0.01, Vector4());
            }
        }
    }
}

void Rubik::setAndStartRotationFace(FaceSide faceSide)
{
    m_faceToRotate = faceSide;
    m_isRotating = true;
}

void Rubik::changeRotationDirection()
{
    m_rotationdirection *= -1;
}

void Rubik::rotationManager()
{
    if (m_isRotating) {
        return;
    }

    switch (m_faceToRotate) {
    case Front:
        rotateFrontFace();
        break;
    case Back:
        rotateBackFace();
        break;    
    case Right:
        rotateRigthFace();
        break;
    case Left:
        rotateLeftFace();
        break;
    case Top:
        rotateTopFace();
        break;
    case Bothom:
        rotateBothomFace();
        break;
    }
}

void Rubik::rotateFrontFace()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 6; l++) {
                    for (int m = 0; m < 4; m++) {
                        m_cubeMatriz[i][j][2].m_faces[l].m_vertex[m] = Transformaciones::RotateY(-0.52, m_cubeMatriz[i][j][2].m_faces[l].m_vertex[m]);
                    }
                }
            //}
        }
    }
}

//for (int i = 0; i < 3; i++) {
//    for (int j = 0; j < 3; j++) {
//        for (int k = 0; k < 3; k++) {
//            for (int l = 0; l < 6; l++) {
//                for (int m = 0; m < 4; m++) {
//                    m_rubik.m_cubeMatriz[i][2][k].m_faces[l].m_vertex[m] = Transformaciones::RotateY(0.52, m_rubik.m_cubeMatriz[i][2][k].m_faces[l].m_vertex[m]);
//                }
//            }
//        }
//    }
//}
