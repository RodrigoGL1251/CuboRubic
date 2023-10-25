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

