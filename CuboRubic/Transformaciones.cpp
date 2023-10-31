#include "Transformaciones.h"
#include <cmath>
#define PI 3.141592
//Traslacion
    //Recive el cambio de las componentes, y el vector de posicion actual
 Vector3 Transformaciones::Translate(float translateX, float translateY, float translateZ, Vector3 position)
 {
    //matriz de traslacion
    Vector4 traslationMatrix[] = {Vector4(1, 0, 0, translateX),
                                  Vector4(0, 1, 0, translateY),
                                  Vector4(0, 0, 1, translateZ),
                                  Vector4(0, 0, 0,     1     )};
    //Matriz de posicion actual
    Vector4 actualPosition = Vector4(position.x, position.y, position.z, 1);
    //Matriz de posicion final
    Vector4 finalPosition = Vector4(0, 0, 0, 0);

    //Multiplicacion de matrices
    for (int i = 0; i < 4; i++)
    {
        float aux = traslationMatrix[i].x * actualPosition.x;
        aux += traslationMatrix[i].y * actualPosition.y;
        aux += traslationMatrix[i].z * actualPosition.z;
        aux += traslationMatrix[i].w * actualPosition.w;

        switch (i)
        {
        case 0:
            finalPosition.x = aux;
            break;
        case 1:
            finalPosition.y = aux;
            break;
        case 2:
            finalPosition.z = aux;
            break;
        case 3:
            finalPosition.w = aux;
            break;
        default:
            break;
        }
    }

    //Regresa vector de posicion
    return Vector3(finalPosition.x, finalPosition.y, finalPosition.z);
}



//Rotar en el eje x
Vector3 Transformaciones::RotateX(float grados, Vector3 position)
{
    //Convertir grados a radianes
    float radian = (grados * PI) / 180;

    //Matriz de rotacion en x
    Vector4 rotationMatrix[] = {Vector4(1,      0     ,       0     ,       0),
                                Vector4(0, cos(radian), -sin(radian),       0),
                                Vector4(0, sin(radian),  cos(radian),       0),
                                Vector4(0,      0     ,       0     ,       1)};
    //Matriz de posicion actual
    Vector4 actualPosition =  Vector4(position.x, position.y, position.z, 1);
    //Matriz de posicion final
    Vector4 finalPosition =  Vector4(0, 0, 0, 0);

    //Multiplicacion de matrices
    for (int i = 0; i < 4; i++)
    {
        float aux = rotationMatrix[i].x * actualPosition.x;
        aux += rotationMatrix[i].y * actualPosition.y;
        aux += rotationMatrix[i].z * actualPosition.z;
        aux += rotationMatrix[i].w * actualPosition.w;

        switch (i)
        {
        case 0:
            finalPosition.x = aux;
            break;
        case 1:
            finalPosition.y = aux;
            break;
        case 2:
            finalPosition.z = aux;
            break;
        case 3:
            finalPosition.w = aux;
            break;
        default:
            break;
        }
    }

    //Regresa vector de posicion
    return  Vector3(finalPosition.x, finalPosition.y, finalPosition.z);
}



//Rotar en el eje y
Vector3 Transformaciones::RotateY(float grados, Vector3 position)
{
    //Convertir grados a radianes
    float radian = (grados * PI) / 180;

    //Matriz de rotacion en y
    Vector4 rotationMatrix[] = { Vector4(cos(radian) , 0, sin(radian), 0),
                                 Vector4(     0      , 1,      0     , 0),
                                 Vector4(-sin(radian), 0, cos(radian), 0),
                                 Vector4(     0      , 0,      0     , 1)};
    //Matriz de posicion actual
    Vector4 actualPosition = Vector4(position.x, position.y, position.z, 1);
    //Matriz de posicion final
    Vector4 finalPosition = Vector4(0, 0, 0, 0);

    //Multiplicacion de matrices
    for (int i = 0; i < 4; i++)
    {
        float aux = rotationMatrix[i].x * actualPosition.x;
        aux += rotationMatrix[i].y * actualPosition.y;
        aux += rotationMatrix[i].z * actualPosition.z;
        aux += rotationMatrix[i].w * actualPosition.w;

        switch (i)
        {
        case 0:
            finalPosition.x = aux;
            break;
        case 1:
            finalPosition.y = aux;
            break;
        case 2:
            finalPosition.z = aux;
            break;
        case 3:
            finalPosition.w = aux;
            break;
        default:
            break;
        }
    }

    //Regresa vector de posicion
    return Vector3(finalPosition.x, finalPosition.y, finalPosition.z);
}



//Rotar en el eje z
 Vector3 Transformaciones::RotateZ(float grados, Vector3 position)
{
    //Convertir grados a radianes
    float radian = (grados * PI) / 180;

    //Matriz de rotacion en Z
    Vector4 rotationMatrix[] = {Vector4(cos(radian),-sin(radian), 0, 0),
                                Vector4(sin(radian), cos(radian), 0, 0),
                                Vector4(     0     ,      0     , 1, 0),
                                Vector4(     0     ,      0     , 0, 1)};
    //Matriz de posicion actual
    Vector4 actualPosition =  Vector4(position.x, position.y, position.z, 1);
    //Matriz de posicion final
    Vector4 finalPosition =  Vector4(0, 0, 0, 0);

    //Multiplicacion de matrices
    for (int i = 0; i < 4; i++)
    {
        float aux = rotationMatrix[i].x * actualPosition.x;
        aux += rotationMatrix[i].y * actualPosition.y;
        aux += rotationMatrix[i].z * actualPosition.z;
        aux += rotationMatrix[i].w * actualPosition.w;

        switch (i)
        {
        case 0:
            finalPosition.x = aux;
            break;
        case 1:
            finalPosition.y = aux;
            break;
        case 2:
            finalPosition.z = aux;
            break;
        case 3:
            finalPosition.w = aux;
            break;
        default:
            break;
        }
    }

    //Regresa vector de posicion
    return Vector3(finalPosition.x, finalPosition.y, finalPosition.z);
}
