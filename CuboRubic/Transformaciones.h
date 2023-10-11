#pragma once
#include "Vector3.h"
#include "Vector4.h"

class Transformaciones
{
public:
    //Traslacion
    //Recive el cambio de las componentes, y el vector de posicion actual
     static Vector3 Translate(float translateX, float translateY, float translateZ, Vector3 position);
     //Rotar en el eje x
    static Vector3 RotateX(float grados, Vector3 position);
    //Rotar en el eje y
    static Vector3 RotateY(float grados, Vector3 position);
    //Rotar en el eje z
    static Vector3 RotateZ(float grados, Vector3 position);
};

