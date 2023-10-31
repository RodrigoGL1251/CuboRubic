#include "Rubik.h"
#include "Transformaciones.h"
#include <iostream>
using namespace std;

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
                m_cubeMatriz[i][j][k] = Cube(cubePivot, thirdOfSize-0.03, Vector4());
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
    if (!m_isRotating) {
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
            for (int l = 0; l < 6; l++) {
                for (int m = 0; m < 4; m++) {
                    m_cubeMatriz[i][j][2].m_faces[l].m_vertex[m] = Transformaciones::RotateZ(m_rotationSpeed * m_rotationdirection, m_cubeMatriz[i][j][2].m_faces[l].m_vertex[m]);
                    
                }
            }            
        }
    }
    m_currentRotateGrades += m_rotationSpeed;
    
    if (m_currentRotateGrades == 90) {
        Cube subMatriz[3][3] {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                subMatriz[i][j] = m_cubeMatriz[i][j][2];
            }
        }
        if (m_rotationdirection < 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[j][2 - i][2] = subMatriz[i][j];
                }
            }
        }
        else{
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[2-j][i][2] = subMatriz[i][j];
                }
            }
        }

        m_currentRotateGrades = 0;
        m_isRotating = false;
    }
}
void Rubik::rotateBackFace()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int l = 0; l < 6; l++) {
                for (int m = 0; m < 4; m++) {
                    m_cubeMatriz[i][j][0].m_faces[l].m_vertex[m] = Transformaciones::RotateZ(m_rotationSpeed * m_rotationdirection, m_cubeMatriz[i][j][0].m_faces[l].m_vertex[m]);

                }
            }
        }
    }
    m_currentRotateGrades += m_rotationSpeed;
    std::cout << m_currentRotateGrades << std::endl;
    if (m_currentRotateGrades == 90) {
        Cube subMatriz[3][3]{};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                subMatriz[i][j] = m_cubeMatriz[i][j][0];
            }
        }
        if (m_rotationdirection < 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[j][2 - i][0] = subMatriz[i][j];
                }
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[2 - j][i][0] = subMatriz[i][j];
                }
            }
        }
        m_currentRotateGrades = 0;
        m_isRotating = false;

    }
}
void Rubik::rotateRigthFace()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int l = 0; l < 6; l++) {
                for (int m = 0; m < 4; m++) {
                    m_cubeMatriz[2][i][j].m_faces[l].m_vertex[m] = Transformaciones::RotateX(m_rotationSpeed * m_rotationdirection, m_cubeMatriz[2][i][j].m_faces[l].m_vertex[m]);

                }
            }
        }
    }
    m_currentRotateGrades += m_rotationSpeed;
    std::cout << m_currentRotateGrades << std::endl;
    if (m_currentRotateGrades == 90) {
        Cube subMatriz[3][3]{};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                subMatriz[i][j] = m_cubeMatriz[2][i][j];
            }
        }
        if (m_rotationdirection < 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[2][j][2 - i] = subMatriz[i][j];
                }
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[2][2 - j][i] = subMatriz[i][j];
                }
            }
        }
        m_currentRotateGrades = 0;
        m_isRotating = false;

    }
}
void Rubik::rotateLeftFace()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int l = 0; l < 6; l++) {
                for (int m = 0; m < 4; m++) {
                    m_cubeMatriz[0][i][j].m_faces[l].m_vertex[m] = Transformaciones::RotateX(m_rotationSpeed * m_rotationdirection, m_cubeMatriz[0][i][j].m_faces[l].m_vertex[m]);

                }
            }
        }
    }
    m_currentRotateGrades += m_rotationSpeed;
    std::cout << m_currentRotateGrades << std::endl;
    if (m_currentRotateGrades == 90) {
        Cube subMatriz[3][3]{};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                subMatriz[i][j] = m_cubeMatriz[0][i][j];
            }
        }
        if (m_rotationdirection < 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[0][j][2 - i] = subMatriz[i][j];
                }
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[0][2 - j][i] = subMatriz[i][j];
                }
            }
        }
        m_currentRotateGrades = 0;
        m_isRotating = false;

    }
}
void Rubik::rotateTopFace()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int l = 0; l < 6; l++) {
                for (int m = 0; m < 4; m++) {
                    m_cubeMatriz[i][0][j].m_faces[l].m_vertex[m] = Transformaciones::RotateY(m_rotationSpeed * m_rotationdirection, m_cubeMatriz[i][0][j].m_faces[l].m_vertex[m]);

                }
            }
        }
    }
    m_currentRotateGrades += m_rotationSpeed;
    std::cout << m_currentRotateGrades << std::endl;
    if (m_currentRotateGrades == 90) {
        Cube subMatriz[3][3]{};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                subMatriz[i][j] = m_cubeMatriz[i][0][j];
            }
        }
        if (m_rotationdirection > 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[j][0][2 - i] = subMatriz[i][j];
                }
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[2 - j][0][i] = subMatriz[i][j];
                }
            }
        }
        m_currentRotateGrades = 0;
        m_isRotating = false;

    }
}
void Rubik::rotateBothomFace()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int l = 0; l < 6; l++) {
                for (int m = 0; m < 4; m++) {
                    m_cubeMatriz[i][2][j].m_faces[l].m_vertex[m] = Transformaciones::RotateY(m_rotationSpeed * m_rotationdirection, m_cubeMatriz[i][2][j].m_faces[l].m_vertex[m]);

                }
            }
        }
    }
    m_currentRotateGrades += m_rotationSpeed;
    std::cout << m_currentRotateGrades << std::endl;
    if (m_currentRotateGrades == 90) {
        Cube subMatriz[3][3]{};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                subMatriz[i][j] = m_cubeMatriz[i][2][j];
            }
        }
        if (m_rotationdirection > 0) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[j][2][2 - i] = subMatriz[i][j];
                }
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    m_cubeMatriz[2 - j][2][i] = subMatriz[i][j];
                }
            }
        }
        m_currentRotateGrades = 0;
        m_isRotating = false;

    }
}