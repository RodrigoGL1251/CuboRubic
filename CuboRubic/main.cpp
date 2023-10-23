#include <GL/glut.h>
#include<iostream>
#include"Rubik.h"
#include <ctime>


enum DirectionOfRotation {
    rigth,
    left,
    top,
    botttom
};
void display(void);
void generateCube(float size, float x, float y, float z);
void generateCubeRubik(float size, float x, float y, float z);

DirectionOfRotation directionOfrotation;
Rubik m_rubik = Rubik();

unsigned t0, t1;
double m_time;
double m_deltaTime;
double m_previousTime;
float m_rotate_x = 0;
float m_rotate_y = 0;
bool m_rotateFace = false;
bool m_rotateTop = false;
bool m_rotateBottom = false;
bool m_rotateRubik = false;

int main(int argc, char** argv)
{
    t0 = clock();
    glutInit(&argc, argv);                                      //inicia el glut
    glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE | GLUT_RGB);   //Estable ce la pantalla con doble buffer con los colores rgba
    glutInitWindowPosition(50, 50);                             //establecemos posicion de la pantalla
    glutInitWindowSize(500, 500);                               //Establecemos tamaño de la pantalla
    glutCreateWindow("Cubo Rubik");                             //Nombre de la ventana
    glEnable(GL_DEPTH_TEST);                                    //permite 3d y rotacion
    
    glutDisplayFunc(display);                                   //Dibujamos pantalla
    
    glutMainLoop();

    return 0;
}

void specialKey() {
}

void display(void) {
    glClearColor(0, 0, 0, 0);                               ///Color de fondo
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     //Borrando pantalla
    //glMatrixMode(GL_PROJECTION);                          //Modo de proyeccion
    glLoadIdentity();                                       //Cargando matriz de identidad
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);             //Proyeccion ortografica dentro del cubo señalado
    gluPerspective(60, 1, 1, 100);                          //Proyeccion perspectiva dentro del cubo señalado
    glTranslatef(0, 0, -2);                                 //Alejando el cuadrado del observador dos unidades en el eje z
    glMatrixMode(GL_MODELVIEW);                             //Modo de modelado
    generateCubeRubik(0.8, 0, 0, 0);                        //Genera los 27 cubos del rubik

    /*glFlush();*/                                          //forzando el dibujado
    glutSwapBuffers();                                      //cambiando de buffer para que se vea mas fluida(se necesita doble buffer)
}

void generateCube(float size, float x, float y, float z) {
    float halfSize = size / 2;
    //Front
    glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    glColor3f(0, 0, 1);                                     //color del cuadrado azul
    glVertex3f(x - halfSize, y + halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x - halfSize, y - halfSize, z + halfSize);
    glVertex3f(x + halfSize, y - halfSize, z + halfSize);
    glVertex3f(x + halfSize, y + halfSize, z + halfSize);
    glEnd();
    //Left
    glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    glColor3f(1, 0, 0);                                     //color del cuadrado rojo
    glVertex3f(x - halfSize, y + halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x - halfSize, y + halfSize, z - halfSize);
    glVertex3f(x - halfSize, y - halfSize, z - halfSize);
    glVertex3f(x - halfSize, y - halfSize, z + halfSize);
    glEnd();
    //Back
    glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    glColor3f(0, 1, 0);                                     //color del cuadrado green
    glVertex3f(x - halfSize, y + halfSize, z - halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x + halfSize, y + halfSize, z - halfSize);
    glVertex3f(x + halfSize, y - halfSize, z - halfSize);
    glVertex3f(x - halfSize, y - halfSize, z - halfSize);
    glEnd();
    //Right
    glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    glColor3f(1,0.5,1);                                     //color del cuadrado naranja
    glVertex3f(x + halfSize, y + halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x + halfSize, y - halfSize, z + halfSize);
    glVertex3f(x + halfSize, y - halfSize, z - halfSize);
    glVertex3f(x + halfSize, y + halfSize, z - halfSize);
    glEnd();
    //Up
    glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    glColor3f(1, 1, 1);                                     //color del cuadrado blanco
    glVertex3f(x - halfSize, y + halfSize, z +halfSize);    //Coordenadas del vertice superior izquierdo
    glVertex3f(x + halfSize, y + halfSize, z +halfSize);
    glVertex3f(x - halfSize, y + halfSize, z -halfSize);
    glVertex3f(x + halfSize, y + halfSize, z -halfSize); 
    glEnd();
    //Down
    glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    glColor3f(1, 1, 0);                                     //color del cuadrado amarillo
    glVertex3f(x - halfSize, y - halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x + halfSize, y - halfSize, z + halfSize);
    glVertex3f(x + halfSize, y - halfSize, z - halfSize);
    glVertex3f(x - halfSize, y - halfSize, z - halfSize);
    glEnd();
}

void generateCubeRubik(float size, float x, float y, float z) {
    float thirdOfSize = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                generateCube(thirdOfSize-0.025, x + thirdOfSize * m_rubik.m_rubikMatriz[i][j][k].x, y + thirdOfSize * m_rubik.m_rubikMatriz[i][j][k].y, z + thirdOfSize * m_rubik.m_rubikMatriz[i][j][k].z);
            }
        }
    }
}