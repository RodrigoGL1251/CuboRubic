#include <GL/glut.h>
#include"Rubik.h"
#include <ctime>
#include "Transformaciones.h"


#include <iostream>
using namespace std;


enum DirectionOfRotation {
    rigth,
    left,
    top,
    botttom
};


void display(void);
void generateCube(/*float size, float x, float y, float z*/);
//void generateCubeRubik(float size, float x, float y, float z);
void input(unsigned char key, int x, int y);
void update();

DirectionOfRotation directionOfrotation;
Rubik m_rubik;



int main(int argc, char** argv)
{
    m_rubik = Rubik(Vector3(), 1);
    glutInit(&argc, argv);                                      //inicia el glut
    glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE | GLUT_RGB);    //Estable ce la pantalla con doble buffer con los colores rgba
    glutInitWindowPosition(50, 50);                             //establecemos posicion de la pantalla
    glutInitWindowSize(500, 500);                               //Establecemos tamaño de la pantalla
    glutCreateWindow("Cubo Rubik");                             //Nombre de la ventana
    glEnable(GL_DEPTH_TEST);                                    //Permite 3d y rotacion
    
    glutDisplayFunc(display);                                   //Se le pasa la funcion para dibujar la pantalla
    glutKeyboardFunc(input);                                    //Se le pasa la funcion que se usara para la entrada del teclado
    glutIdleFunc(update);                                       //establece las funciones que se van a estar actualizando
    glutMainLoop();

    return 0;
}
void update() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 6; l++) {
                    for (int m = 0; m < 4; m++) {
                        m_rubik.m_cubeMatriz[i][2][k].m_faces[l].m_vertex[m] = Transformaciones::RotateY(0.52, m_rubik.m_cubeMatriz[i][2][k].m_faces[l].m_vertex[m]);
                        m_rubik.m_cubeMatriz[i][0][k].m_faces[l].m_vertex[m] = Transformaciones::RotateY(-0.52, m_rubik.m_cubeMatriz[i][0][k].m_faces[l].m_vertex[m]);
                    }
                }
            }
        }
    }
    glutPostRedisplay();
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
    //generateCubeRubik(0.8, 0, 0, 0);                        //Genera los 27 cubos del rubik
    generateCube();

    /*glFlush();*/                                          //forzando el dibujado
    glutSwapBuffers();                                      //cambiando de buffer para que se vea mas fluida(se necesita doble buffer)
}

void generateCube(/*float size, float x, float y, float z*/) {
    Vector3 color;
    Vector3 vertex;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 6; l++) {
                    color = m_rubik.m_cubeMatriz[i][j][k].m_faces[l].m_color;
                    glBegin(GL_POLYGON);                                    //dibujando un cuadrado
                    glColor3f(color.x, color.y, color.z);             //color del cuadrado 
                    for (int m = 0; m < 4; m++) {
                        vertex = m_rubik.m_cubeMatriz[i][j][k].m_faces[l].m_vertex[m];
                        /*cout << vertex.z << " " << vertex.y << " " << vertex.z << endl;*/
                        glVertex3f(vertex.x, vertex.y, vertex.z);   //Coordenadas de los vertices
                    }
                    glEnd();
                }  
            }
        }
    }


    //float halfSize = size / 2;
    ////Front
    //glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    //glColor3f(0, 0, 1);                                     //color del cuadrado azul
    //glVertex3f(x - halfSize, y + halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    //glVertex3f(x - halfSize, y - halfSize, z + halfSize);
    //glVertex3f(x + halfSize, y - halfSize, z + halfSize);
    //glVertex3f(x + halfSize, y + halfSize, z + halfSize);
    //glEnd();
    ////Left
    //glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    //glColor3f(1, 0, 0);                                     //color del cuadrado rojo
    //glVertex3f(x - halfSize, y + halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    //glVertex3f(x - halfSize, y + halfSize, z - halfSize);
    //glVertex3f(x - halfSize, y - halfSize, z - halfSize);
    //glVertex3f(x - halfSize, y - halfSize, z + halfSize);
    //glEnd();
    ////Back
    //glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    //glColor3f(0, 1, 0);                                     //color del cuadrado green
    //glVertex3f(x - halfSize, y + halfSize, z - halfSize);   //Coordenadas del vertice superior izquierdo
    //glVertex3f(x + halfSize, y + halfSize, z - halfSize);
    //glVertex3f(x + halfSize, y - halfSize, z - halfSize);
    //glVertex3f(x - halfSize, y - halfSize, z - halfSize);
    //glEnd();
    ////Right
    //glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    //glColor3f(1,0.5,1);                                     //color del cuadrado naranja
    //glVertex3f(x + halfSize, y + halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    //glVertex3f(x + halfSize, y - halfSize, z + halfSize);
    //glVertex3f(x + halfSize, y - halfSize, z - halfSize);
    //glVertex3f(x + halfSize, y + halfSize, z - halfSize);
    //glEnd();
    ////Up
    //glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    //glColor3f(1, 1, 1);                                     //color del cuadrado blanco
    //glVertex3f(x - halfSize, y + halfSize, z +halfSize);    //Coordenadas del vertice superior izquierdo
    //glVertex3f(x + halfSize, y + halfSize, z +halfSize);
    //glVertex3f(x - halfSize, y + halfSize, z -halfSize);
    //glVertex3f(x + halfSize, y + halfSize, z -halfSize); 
    //glEnd();
    ////Down
    //glBegin(GL_POLYGON);                                    //dibujando un cuadrado
    //glColor3f(1, 1, 0);                                     //color del cuadrado amarillo
    //glVertex3f(x - halfSize, y - halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    //glVertex3f(x + halfSize, y - halfSize, z + halfSize);
    //glVertex3f(x + halfSize, y - halfSize, z - halfSize);
    //glVertex3f(x - halfSize, y - halfSize, z - halfSize);
    //glEnd();
}

//void generateCubeRubik(float size, float x, float y, float z) {
//    float thirdOfSize = size / 3;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            for (int k = 0; k < 3; k++) {
//                generateCube(thirdOfSize-0.025, x + thirdOfSize * m_rubik.m_cubeMatriz[i][j][k].x, y + thirdOfSize * m_rubik.m_cubeMatriz[i][j][k].y, z + thirdOfSize * m_rubik.m_cubeMatriz[i][j][k].z);
//            }
//        }
//    }
//}

void input(unsigned char key, int x, int y) {
    /*if (m_rubik.m_isRotatingFrontX && m_rubik.m_isRotatingMidleX && m_rubik.m_isRotatingBackX && m_rubik.m_isRotatingFrontY && m_rubik.m_isRotatingMidleY && m_rubik.m_isRotatingBackY && m_rubik.m_isRotatingFrontZ && m_rubik.m_isRotatingMidleZ && m_rubik.m_isRotatingBackZ) {
        switch (key) {
        case 'q':
            m_rubik.m_isRotatingBackX = true;
            m_rubik.m_rotateDirection = 1;
            break;
        case 'a':
            m_rubik.m_isRotatingMidleX = true;
            m_rubik.m_rotateDirection = 1;
            break;
        case 'z':
            m_rubik.m_isRotatingFrontX = true;
            m_rubik.m_rotateDirection = 1;
            break;
        case 'w':
            m_rubik.m_isRotatingBackX = true;
            m_rubik.m_rotateDirection = -1;
            break;
        case 's':
            m_rubik.m_isRotatingMidleX = true;
            m_rubik.m_rotateDirection = -1;
            break;
        case 'x':
            m_rubik.m_isRotatingFrontX = true;
            m_rubik.m_rotateDirection = -1;
            break;
        case 'e':
            m_rubik.m_isRotatingBackY = true;
            m_rubik.m_rotateDirection = 1;
            break;
        case 'd':
            m_rubik.m_isRotatingMidleY = true;
            m_rubik.m_rotateDirection = 1;
            break;
        case 'c':
            m_rubik.m_isRotatingFrontY = true;
            m_rubik.m_rotateDirection = 1;
            break;
        case 'r':
            m_rubik.m_isRotatingBackY = true;
            m_rubik.m_rotateDirection = -1;
            break;
        case 'f':
            m_rubik.m_isRotatingMidleY = true;
            m_rubik.m_rotateDirection = -1;
            break;
        case 'v':
            m_rubik.m_isRotatingFrontY = true;
            m_rubik.m_rotateDirection = -1;
            break;
        case 't':
            m_rubik.m_isRotatingBackZ = true;
            m_rubik.m_rotateDirection = 1;
            break;
        case 'g':
            m_rubik.m_isRotatingMidleZ = true;
            m_rubik.m_rotateDirection = 1;
            break;
        case 'b':
            m_rubik.m_isRotatingFrontZ = true;
            m_rubik.m_rotateDirection = 1;
            break;
        case 'y':
            m_rubik.m_isRotatingBackZ = true;
            m_rubik.m_rotateDirection = -1;
            break;
        case 'h':
            m_rubik.m_isRotatingMidleZ = true;
            m_rubik.m_rotateDirection = -1;
            break;
        case 'n':
            m_rubik.m_isRotatingFrontZ = true;
            m_rubik.m_rotateDirection = -1;
            break;
        default:
            break;
        }
    }   */
}