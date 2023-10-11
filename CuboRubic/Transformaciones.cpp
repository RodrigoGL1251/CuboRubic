#include "Transformaciones.h"
//Traslacion
    //Recive el cambio de las componentes, y el vector de posicion actual
 Vector3 Transformaciones::Translate(float translateX, float translateY, float translateZ, Vector3 position)
 {
    //matriz de traslacion
    Vector4* traslationMatrix = {  Vector4(1, 0, 0, translateX),
                                   Vector4(0, 1, 0, translateY),
                                   Vector4(0, 0, 1, translateZ),
                                   Vector4(0, 0, 0,     1) };
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

        finalPosition[i] = aux;
    }

    //Regresa vector de posicion
    return Vector3(finalPosition.x, finalPosition.y, finalPosition.z);
}



//Rotar en el eje x
Vector3 Transformaciones::RotateX(float grados, Vector3 position)
{
    //Convertir grados a radianes
    float radian = (grados * Mathf.PI) / 180;

    //Matriz de rotacion en x
    Vector4* rotationMatrix = { Vector4(1,      0,                   0,           0),
                                Vector4(0, Mathf.Cos(radian), -Mathf.Sin(radian), 0),
                                Vector4(0, Mathf.Sin(radian),  Mathf.Cos(radian), 0),
                                Vector4(0,      0,                   0,           1) };
    //Matriz de posicion actual
    Vector4 actualPosition =  Vector4(position.x, position.y, position.z, 1f);
    //Matriz de posicion final
    Vector4 finalPosition =  Vector4(0, 0, 0, 0);

    //Multiplicacion de matrices
    for (int i = 0; i < 4; i++)
    {
        float aux = rotationMatrix[i].x * actualPosition.x;
        aux += rotationMatrix[i].y * actualPosition.y;
        aux += rotationMatrix[i].z * actualPosition.z;
        aux += rotationMatrix[i].w * actualPosition.w;

        finalPosition[i] = aux;
    }

    //Regresa vector de posicion
    return new Vector3(finalPosition.x, finalPosition.y, finalPosition.z);
}



//Rotar en el eje y
Vector3 Transformaciones::RotateY(float grados, Vector3 position)
{
    //Convertir grados a radianes
    float radian = (grados * Mathf.PI) / 180f;

    //Matriz de rotacion en y
    Vector4[] rotationMatrix = { new Vector4(Mathf.Cos(radian), 0, Mathf.Sin(radian), 0),
                                new Vector4(0,            1,         0,         0),
                                new Vector4(-Mathf.Sin(radian), 0, Mathf.Cos(radian), 0),
                                new Vector4(0,                  0,         0,         1) };
    //Matriz de posicion actual
    Vector4 actualPosition = new Vector4(position.x, position.y, position.z, 1f);
    //Matriz de posicion final
    Vector4 finalPosition = new Vector4(0f, 0f, 0f, 0f);

    //Multiplicacion de matrices
    for (int i = 0; i < rotationMatrix.Length; i++)
    {
        float aux = rotationMatrix[i].x * actualPosition.x;
        aux += rotationMatrix[i].y * actualPosition.y;
        aux += rotationMatrix[i].z * actualPosition.z;
        aux += rotationMatrix[i].w * actualPosition.w;

        finalPosition[i] = aux;
    }

    //Regresa vector de posicion
    return new Vector3(finalPosition.x, finalPosition.y, finalPosition.z);
}



//Rotar en el eje z
public static Vector3 RotateZ(float grados, Vector3 position)
{
    //Convertir grados a radianes
    float radian = (grados * Mathf.PI) / 180f;

    //Matriz de rotacion en Z
    Vector4[] rotationMatrix = { new Vector4(Mathf.Cos(radian), -Mathf.Sin(radian), 0, 0),
                                new Vector4(Mathf.Sin(radian),  Mathf.Cos(radian), 0, 0),
                                new Vector4(0,                    0,         1, 0),
                                new Vector4(0,                    0,         0, 1) };
    //Matriz de posicion actual
    Vector4 actualPosition = new Vector4(position.x, position.y, position.z, 1f);
    //Matriz de posicion final
    Vector4 finalPosition = new Vector4(0f, 0f, 0f, 0f);

    //Multiplicacion de matrices
    for (int i = 0; i < rotationMatrix.Length; i++)
    {
        float aux = rotationMatrix[i].x * actualPosition.x;
        aux += rotationMatrix[i].y * actualPosition.y;
        aux += rotationMatrix[i].z * actualPosition.z;
        aux += rotationMatrix[i].w * actualPosition.w;

        finalPosition[i] = aux;
    }

    //Regresa vector de posicion
    return new Vector3(finalPosition.x, finalPosition.y, finalPosition.z);
}
