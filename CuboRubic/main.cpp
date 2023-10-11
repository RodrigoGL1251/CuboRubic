#include <GL/glut.h>
#include<iostream>

void display(void);
void generateCube(float size, float x, float y, float z);
void generateCubeRubik(float size, float x, float y, float z);

float rotate_x = 0;
float rotate_y = 0;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          //inicia el glut
    glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE | GLUT_RGBA); //Estable ce la pantalla con doble buffer con los colores rgba
    glutInitWindowPosition(50, 50);                 //establecemos posicion de la pantalla
    glutInitWindowSize(500, 500);                   //Establecemos tamaño de la pantalla
    glutCreateWindow("Cubo Rubik");                 //Nombre de la ventana
    glEnable(GL_DEPTH_TEST);                        //permite 3d y rotacion
    //glutCreateWindow(argv[0]);                      //creamos pantalla

    glutDisplayFunc(display);                       //Dibujamos pantalla
    glutMainLoop();

    return 0;
}

void display(void) {
    glClearColor(0, 0, 0, 0);           ///Color de fondo
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       //Borrando pantalla
    //glMatrixMode(GL_PROJECTION);        //Modo de proyeccion
    glLoadIdentity();                   //Cargando matriz de identidad
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);   //Proyeccion ortografica dentro del cubo señalado
    gluPerspective(60, 1, 1, 100);         //Proyeccion perspectiva dentro del cubo señalado
    glTranslatef(0, 0, -2);                 //Alejando el cuadrado del observador dos unidades en el eje z
    glMatrixMode(GL_MODELVIEW);         //Modo de modelado
    generateCubeRubik(0.8, 0, 0, 0);    //Genera los 27 cubos del rubik

    glFlush();                          //forzando el dibujado
    glutSwapBuffers();
}

void generateCube(float size, float x, float y, float z) {
    float halfSize = size / 2;
    //Front
    glBegin(GL_POLYGON);                                      //dibujando un cuadrado
    glColor3f(0, 0, 1);                                     //color del cuadrado azul
    glVertex3f(x - halfSize, y + halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x - halfSize, y - halfSize, z + halfSize);
    glVertex3f(x + halfSize, y - halfSize, z + halfSize);
    glVertex3f(x + halfSize, y + halfSize, z + halfSize);
    glEnd();
    //Left
    glBegin(GL_POLYGON);                                      //dibujando un cuadrado
    glColor3f(1, 0, 0);                                     //color del cuadrado rojo
    glVertex3f(x - halfSize, y + halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x - halfSize, y + halfSize, z - halfSize);
    glVertex3f(x - halfSize, y - halfSize, z - halfSize);
    glVertex3f(x - halfSize, y - halfSize, z + halfSize);
    glEnd();
    //Back
    glBegin(GL_POLYGON);                                      //dibujando un cuadrado
    glColor3f(0, 1, 0);                                     //color del cuadrado green
    glVertex3f(x - halfSize, y + halfSize, z - halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x + halfSize, y + halfSize, z - halfSize);
    glVertex3f(x + halfSize, y - halfSize, z - halfSize);
    glVertex3f(x - halfSize, y - halfSize, z - halfSize);
    glEnd();
    //Right
    glBegin(GL_POLYGON);                                      //dibujando un cuadrado
    glColor3f(1,0.5,1);                                     //color del cuadrado naranja
    glVertex3f(x + halfSize, y + halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x + halfSize, y - halfSize, z + halfSize);
    glVertex3f(x + halfSize, y - halfSize, z - halfSize);
    glVertex3f(x + halfSize, y + halfSize, z - halfSize);
    glEnd();
    //Up
    glBegin(GL_POLYGON);                                      //dibujando un cuadrado
    glColor3f(1, 1, 1);                                     //color del cuadrado blanco
    glVertex3f(x - halfSize, y + halfSize, z +halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x + halfSize, y + halfSize, z +halfSize);
    glVertex3f(x - halfSize, y + halfSize, z -halfSize);
    glVertex3f(x + halfSize, y + halfSize, z -halfSize); 
    glEnd();
    //Down
    glBegin(GL_POLYGON);                                      //dibujando un cuadrado
    glColor3f(1, 1, 0);                                     //color del cuadrado amarillo
    glVertex3f(x - halfSize, y - halfSize, z + halfSize);   //Coordenadas del vertice superior izquierdo
    glVertex3f(x + halfSize, y - halfSize, z + halfSize);
    glVertex3f(x + halfSize, y - halfSize, z - halfSize);
    glVertex3f(x - halfSize, y - halfSize, z - halfSize);
    glEnd();
}

void generateCubeRubik(float size, float x, float y, float z) {
    float thirdOfSize = size / 3;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            for (int k = -1; k < 2; k++) {
                generateCube(thirdOfSize-0.025, x + thirdOfSize * i, y + thirdOfSize * j, z + thirdOfSize * k);
            }
        }
    }
}